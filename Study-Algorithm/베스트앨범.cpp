//https://programmers.co.kr/learn/courses/30/lessons/42579
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp1(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> playGenre;
	map<string, vector<pair<int, int>>> numGenre;
	for (int i = 0; i < genres.size(); i++) {
		if (playGenre.count(genres[i]) == 0) {
			playGenre.insert(make_pair(genres[i], 0));
			numGenre.insert(make_pair(genres[i], vector<pair<int, int>>()));
		}
		playGenre[genres[i]] += plays[i];
		numGenre[genres[i]].push_back(make_pair(plays[i], i));
	}
	vector <pair<string, int>> sortedPlayGenre;
	for (auto it = playGenre.begin(); it != playGenre.end(); it++) {
		sortedPlayGenre.push_back(make_pair(it->first, it->second));
	}
	sort(sortedPlayGenre.begin(), sortedPlayGenre.end(), cmp1);
	for (auto it = numGenre.begin(); it != numGenre.end(); it++) {
		sort(it->second.begin(), it->second.end(), cmp2);
	}

	for (int i = 0; i < sortedPlayGenre.size(); i++) {
		for (int j = 0; j < numGenre[sortedPlayGenre[i].first].size() && j < 2; j++) {
			answer.push_back(numGenre[sortedPlayGenre[i].first].at(j).second);
		}
	}

	return answer;
}