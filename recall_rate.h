#ifndef RECALL_RATE_H
#define RECALL_RATE_H
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <vector>

void evaluate_recall_rate(std::vector<Rect> faces,std::vector<Rect> faces_ans, Mat *frame);
void evaluate_pos_neg_rate(std::vector<Rect> faces,std::vector<Rect> faces_ans, Mat *frame);
#endif