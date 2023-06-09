#pragma once
#include "StringEx.h"

class CImageUtil
{
public:
	CImageUtil();
	~CImageUtil();

	// GeoTIFF->Jpeg変換
	static bool ConvertTiffToJpeg(const std::wstring& strTiffPath);

	// 凡例画像の作成
	static bool CreateLegendImage(const std::wstring& strColorSetting, const std::wstring& strHeader);

private:

};

