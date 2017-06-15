// lambda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{

	//template <string name, string ip, vector<string> services> using cinemActionNode = <name, ip, services>;
	typedef tuple<string, string, vector<string>> cinemActionNode;

	// node name, ip, services
	cinemActionNode master = { "Master", "10.1.1.41", {"Show Master", "SSMaster", "ProjectorManager", "Computer monitor"} };
	cinemActionNode eagelEye = { "Eagle Eye", "10.1.1.35",{ "EagleEye", "Computer monitor" } };
	cinemActionNode detection01 = { "Detection 01", "10.1.1.61",{ "SSSlave", "Computer monitor" } };
	cinemActionNode detection02 = { "Detection 02", "10.1.1.62",{ "SSSlave", "Computer monitor" } };
	cinemActionNode show01 = { "Show 01", "10.1.1.51",{ "Show", "Computer monitor" } };
	cinemActionNode show02 = { "Show 02", "10.1.1.52",{ "Show", "Computer monitor" } };
	cinemActionNode show03 = { "Show 03", "10.1.1.53",{ "Show", "Computer monitor" } };
	cinemActionNode show04 = { "Show 04", "10.1.1.54",{ "Show", "Computer monitor" } };

	map<int, cinemActionNode> nodes = { 
		{0, master}, 
		{1, eagelEye },
		{2, detection01 },
		{3, detection02 },
		{4, show01 },
		{5, show02 },
		{6, show03 },
		{7, show04 } 
	};


	string nodeName, nodeIP;
	vector<string> nodeServices;

	for( pair<int, cinemActionNode> el : nodes) {

		nodeName.clear();
		nodeIP.clear();
		nodeServices.clear();

		tie(nodeName, nodeIP, nodeServices) = el.second;

		cout << "node id " << el.first << " - " << nodeName <<"\n";
	}
	



    return 0;
}

