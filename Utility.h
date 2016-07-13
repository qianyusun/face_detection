#ifndef UTILITY_H
#define UTILITY_H

#include <iosfwd>
#include <vector>
Class Rect;

int vectorsum(std::vector<int> v);
std::vector<Rect> ReadRectInfo(std::string folder, std::string filename, std::string image_name);
void draw_rects(Mat *frame, std::vector<Rect> faces, int color, int thickness, int lineType);
bool overlap_bool(Rect rectA, std::vector<Rect> answer, int threshold );
std::vector<String> getImageNames (void);

#endif