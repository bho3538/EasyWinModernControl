#include "file.h"

#include <shobjidl.h>
#include <ShlGuid.h>
#include <shlwapi.h>

static IShellItem* pItem = NULL;

HRESULT OpenFileFromFileDialog() {
	HRESULT hr = E_FAIL;
	IFileDialog* pFileDialog = NULL;

	NPCloseFile();

	hr = CoCreateInstance(&CLSID_FileOpenDialog, NULL, CLSCTX_ALL, &IID_IFileDialog, &pFileDialog);

	if (FAILED(hr) || !pFileDialog) {
		goto escapeArea;
	}

	hr = pFileDialog->lpVtbl->Show(pFileDialog, NULL);

	if (FAILED(hr)) {
		goto escapeArea;
	}

	hr = pFileDialog->lpVtbl->GetResult(pFileDialog, &pItem);


escapeArea:

	if (pFileDialog) {
		pFileDialog->lpVtbl->Release(pFileDialog);
	}

	return hr;
}


void NPCloseFile() {
	if (pItem) {
		pItem->lpVtbl->Release(pItem);
		pItem = NULL;
	}
}

HRESULT GetFileData(LPSTR* pBuffer,PULONGLONG pSize) {
	HRESULT hr = E_FAIL;
	IStream* pStream = NULL;
	LPSTR tmpBuffer = NULL;
	STATSTG size = { 0, };
	ULONGLONG totalRead = 0;
	ULONG currentRead = 0;
	
	*pSize = 0;
	*pBuffer = NULL;

	if (!pItem) {
		goto escapeArea;
	}

	hr = pItem->lpVtbl->BindToHandler(pItem, NULL, &BHID_Stream, &IID_IStream, &pStream);
	if (FAILED(hr)) {
		goto escapeArea;
	}

	hr = pStream->lpVtbl->Stat(pStream, &size, STATFLAG_NONAME);
	if (FAILED(hr)) {
		goto escapeArea;
	}

	*pSize = size.cbSize.QuadPart;

	if (pSize > 0) {
		*pBuffer = (LPSTR)malloc(size.cbSize.QuadPart);
		if (!(*pBuffer)) {
			hr = E_OUTOFMEMORY;
			goto escapeArea;
		}
		tmpBuffer = *pBuffer;
		for (;;) {
			hr = pStream->lpVtbl->Read(pStream, tmpBuffer, 4096, &currentRead);
			if (FAILED(hr)) {
				goto escapeArea;
			}
			totalRead += currentRead;
			tmpBuffer += currentRead;

			if (currentRead < 4096) {
				break;
			}
		}
	}

escapeArea:

	if (pStream) {
		pStream->lpVtbl->Release(pStream);
	}

	if (FAILED(hr)) {
		free(*pBuffer);
	}

	return hr;
}

HRESULT ConvertUnicodeBuffer(LPSTR pBuffer, INT size, LPWSTR* pOutUnicodeBuffer, PINT pUnicodeBufferSize) {
	HRESULT hr = E_FAIL;
	if (!IsTextUnicode(pBuffer, size, NULL)) {
		*pUnicodeBufferSize = MultiByteToWideChar(CP_UTF8, 0, pBuffer, size, NULL, 0);
		if (*pUnicodeBufferSize) {
			*pOutUnicodeBuffer = (LPWSTR)malloc((*pUnicodeBufferSize) * sizeof(WCHAR));
			MultiByteToWideChar(CP_UTF8, 0, pBuffer, size, *pOutUnicodeBuffer, *pUnicodeBufferSize);
			hr = S_OK;
		}
	}
	else {
		WORD bom = *((WORD*)pBuffer);
		if (bom == 65279) {
			((WORD*)pBuffer) += 1;
			size -= sizeof(WORD);
		}

		*pOutUnicodeBuffer = (LPWSTR)malloc(size);
		memcpy(*pOutUnicodeBuffer, pBuffer, size);
		*pUnicodeBufferSize = size / sizeof(WCHAR);
		hr = S_OK;
	}

	return hr;
}