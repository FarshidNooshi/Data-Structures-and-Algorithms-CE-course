#include "Headers/Writer.h"

using namespace std;

void Writer::WriteAnswers() {
	for (auto& item : analysedMap) {
		printf("Path from %d to %d will take %lf. \n", item.first.src, item.first.dst, item.second.timeElapsed);
		cout << "points in the path from source to target :=\n";
		for (auto& u : item.second.path)
			cout << u.src.id << ' ';
		cout << item.first.dst << '\n';
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	}
}