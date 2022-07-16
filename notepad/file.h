#pragma once

#include "stdafx.h"

HRESULT OpenFileFromFileDialog();

HRESULT GetFileData(LPSTR* pBuffer,PULONGLONG pSize);

HRESULT ConvertUnicodeBuffer(LPSTR pBuffer, INT size, LPWSTR* pOutUnicodeBuffer, PINT pUnicodeBufferSize);

void NPCloseFile();
