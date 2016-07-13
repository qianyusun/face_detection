#ifndef RECALL_RATE_H
#define RECALL_RATE_H
#include <vector>
class Rect;
class Mat;


void evaluate_recall_rate(std::vector<Rect> faces,std::vector<Rect> faces_ans, Mat *frame);
void evaluate_pos_neg_rate(std::vector<Rect> faces,std::vector<Rect> faces_ans, Mat *frame);



#endif