#include "History.h"

Void History::push(Bitmap^ bmp) {
	if (current != history.size() - 1 && history.size() != 0) {
		history.erase(history.begin() + current + 1, history.begin() + history.size());
	} 
	if (history.size() == maxSize) {
		history.erase(history.begin() + 0);
	}
	history.push_back(bmp);
	current = history.size() - 1;
}

bool History::canBack() {
	return current != 0;
}

bool History::canForward() {
	return current != history.size() - 1 && history.size() != 1;
}

Bitmap^ History::back() {
	if (canBack()) {
		current -= 1;
	}
	return history[current];
}

Bitmap^ History::forward() {
	if (canForward()) {
		current += 1;
	}
	return history[current];
}

Void History::setMaxSize(int maxSize) {
	this->maxSize = maxSize;
}