#include "Headers/Writer.h"

void Writer::WriteAnswers() {
	for (auto& item : analysedMap) {
		cout << "Path From " << item.first.src << " to " << item.first.dst << " will take " << item.second.timeElapsed << '\n';
		cout << "points in the path from source to target :=\n";
		for (auto u : item.second.path)
			cout << u.src << ' ';
		cout << item.first.dst << '\n';
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	}
}