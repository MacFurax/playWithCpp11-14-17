// lambda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;


//template <string name, string ip, vector<string> services> using cinemActionNode = <name, ip, services>;
typedef tuple<string, string, vector<string>> cinemActionNode;

void listNodes(vector<cinemActionNode>& nodes)
{
	string nodeName, nodeIP;
	vector<string> nodeServices;

	for (auto el : nodes) {

		nodeName.clear();
		nodeIP.clear();
		nodeServices.clear();

		tie(nodeName, nodeIP, nodeServices) = el;

		cout << std::left << setw(20) << nodeName << setw(20) << nodeIP << " ";
		for (auto s : nodeServices) {
			cout << s << "/";
		}
		cout << "\n";
	}
	cout << "\n";
}

void listNodesInterator(vector<cinemActionNode>::iterator start, vector<cinemActionNode>::iterator end)
{
	string nodeName, nodeIP;
	vector<string> nodeServices;

	for_each(start, end, [&nodeName, &nodeIP, &nodeServices]( auto el) {

		nodeName.clear();
		nodeIP.clear();
		nodeServices.clear();

		tie(nodeName, nodeIP, nodeServices) = el;

		cout << std::left << setw(20) << nodeName << setw(20) << nodeIP << " ";
		for (auto s : nodeServices) {
			cout << s << "/";
		}
		cout << "\n";


	});

	cout << "\n";

	/*for (auto el : nodes) {

		nodeName.clear();
		nodeIP.clear();
		nodeServices.clear();

		tie(nodeName, nodeIP, nodeServices) = el;

		cout << std::left << setw(20) << nodeName << setw(20) << nodeIP << " ";
		for (auto s : nodeServices) {
			cout << s << "/";
		}
		cout << "\n";
	}
	cout << "\n";*/
}

int main()
{

	// node name, ip, services
	cinemActionNode master = { "Master", "10.1.1.41", {"Show Master", "SSMaster", "ProjectorManager", "Computer monitor"} };
	cinemActionNode eagelEye = { "Eagle Eye", "10.1.1.35",{ "EagleEye", "Computer monitor" } };
	cinemActionNode detection01 = { "Detection 01", "10.1.1.61",{ "SSSlave", "Computer monitor" } };
	cinemActionNode detection02 = { "Detection 02", "10.1.1.62",{ "SSSlave", "Computer monitor" } };
	cinemActionNode show01 = { "Show 01", "10.1.1.51",{ "Show", "Computer monitor" } };
	cinemActionNode show02 = { "Show 02", "10.1.1.52",{ "Show", "Computer monitor" } };
	cinemActionNode show03 = { "Show 03", "10.1.1.53",{ "Show", "Computer monitor" } };
	cinemActionNode show04 = { "Show 04", "10.1.1.54",{ "Show", "Computer monitor" } };

	vector<cinemActionNode> nodes = { 
		{master}, 
		{eagelEye },
		{detection01 },
		{detection02 },
		{show01 },
		{show02 },
		{show03 },
		{show04 } 
	};
	
	cout << "vector as is \n";
	listNodes(nodes);
	
	typedef function<bool(const cinemActionNode&, const cinemActionNode&)> cinemActionNodeSorter;

	cinemActionNodeSorter cinemActionNodeSortByName = [](const cinemActionNode &a, const cinemActionNode &b) { return get<0>(a) < get<0>(b); };
	cinemActionNodeSorter cinemActionNodeSortByIP = [](const cinemActionNode &a, const cinemActionNode &b) { return get<1>(a) < get<1>(b); };
	cinemActionNodeSorter &cinemActionSortFunction = cinemActionNodeSortByName;

	// sort by name
	cout << "\nvector sorted by name\n";
	sort( begin(nodes), end(nodes), cinemActionSortFunction);
	//listNodes(nodes);
	listNodesInterator(begin(nodes), end(nodes));

	// sort by IP
	cinemActionSortFunction = cinemActionNodeSortByIP;
	cout << "\nvector sorted by IP\n";
	sort(begin(nodes), end(nodes), cinemActionSortFunction);
	//listNodes(nodes);
	listNodesInterator(begin(nodes), end(nodes));

	// find node that only use a given service
	string serviceToMatch = "SSSlave";
	cout << "\nOnly with " << serviceToMatch << "service\n";
	auto pivot = partition(begin(nodes), end(nodes), [serviceToMatch](auto node) { 
		for (string s : get<2>(node))
		{
			if (s == serviceToMatch) return true;
		}
		return false;
	});

	listNodesInterator(begin(nodes), pivot);

    return 0;
}

