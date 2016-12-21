#include "LabelGenerator.h"

using namespace std;


int LabelGenerator::ifCount(0),
	LabelGenerator::lableCount(0);


Label* LabelGenerator::getLabel() {
	Label* l = new Label("Label" + to_string(lableCount));
	lableCount++;
	return l;
}

vector<Label*>* LabelGenerator::getIfLabel() {
	vector<Label*>* labels = new vector<Label*>();
	labels->push_back(new Label("then_" + to_string(ifCount)));
	labels->push_back(new Label("else_" + to_string(ifCount)));
	ifCount++;
	return labels;
}

