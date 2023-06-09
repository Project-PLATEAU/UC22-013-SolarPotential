#pragma once
#include <vector>
#include <map>
#include <string>
#include "ReflectionSimulator.h"
#include "UIParam.h"

class CResultKeyData;

class CReflectionSimulateMng
{
public:
	CReflectionSimulateMng()
		: m_outDir("")
		, m_year(2021)
		, m_pParam(nullptr)
	{}

	void Exec(const std::string& outDir, UIParam* pUIParam, int year);

private:
	// 光害時間
	struct ReflectionEffectTime
	{
		int summer{ 0 };	// 夏至
		int spring{ 0 };	// 春分
		int winter{ 0 };	// 冬至
	};

	// 解析結果格納先
	std::string m_outDir;
	// 解析年
	int m_year;
	// 設定パラメータ
	UIParam* m_pParam;

	bool ReflectionSim(std::vector<CAnalysisReflectionOneDay>& result);

	bool ReflectionEffect(const std::vector<CAnalysisReflectionOneDay>& result);

	bool OutReflectionEffect(const std::string csvfile,
		const std::map<CResultKeyData, ReflectionEffectTime>& effectResult);

	// 建物名からメッシュIDを取得
	bool GetMeshID(const std::string& buildingID, std::string& meshID) const;

};

class CResultKeyData
{
public:
	string buildingId;	// 建物ID
	int index;			// 建物ID並び順

public:
	CResultKeyData() : buildingId(""), index(0) {}
	CResultKeyData(const string& buildingId, int index)
		: buildingId(buildingId), index(index) {}

	bool operator <(const CResultKeyData& a) const
	{
		// indexで比較して同じであればbuildingIdで比較する
		return tie(index, buildingId) < tie(a.index, a.buildingId);
	}
};
