#include "Utility.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int vectorsum(std::vector<int> v){
    int sum=0;
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it){    
        sum += *it;
    }
    return sum;
}

std::vector<Rect> ReadRectInfo (string folder, string filename, string image_name){
    std::vector<Rect> Ans;
    //Read in real positions
    ifstream filestream;
    filename = folder + "/" + filename;
    filestream.open(filename.c_str());
    if ( !filestream.is_open()){
        cout << "open failed" << endl;
        exit(1);
    }
    std::string line;
    std::string word;
    int face_num;
    int x,y,w,h;
    while (getline(filestream, line)) {
        istringstream iss(line);
        iss >> word;    
        if (word == image_name) {
            iss >> face_num;
            for (int i = 0; i < face_num; i++ ){
                    iss >> x;
                    iss >> y;
                    iss >> w;
                    iss >> h;
                    //cout << "x=" << x <<  " y=" << y << " x2=" << x+w << " y2=" << y+h <<"\n";
                    Ans.push_back(Rect(x,y,w,h));
            }
        }
    }
    filestream.close();
    //cout << Ans[0].x <<Ans[0].y<< Ans[0].width<< Ans[0].height<<"\n"; 
    return Ans;
}



/* overlap_bool
 * Compare rectangle "rectA" with every element in rectangle vector "answer".
 *  If the overlap area over the original area of "rectA" is larger than 
 * "threshold" in percentage, return 1, return 0 otherwise.
 * 
 */
bool overlap_bool(Rect rectA, std::vector<Rect> answer, int threshold ){
    int x1,y1,x2,y2,overlap;
    for (int j = 0; j < answer.size(); j++ ){//per face detected
        x1 = max(rectA.x,answer[j].x);
        x2 = min(rectA.x+rectA.width,answer[j].x+answer[j].width);
        y1 = max(rectA.y,answer[j].y);
        y2 = min(rectA.y+rectA.height,answer[j].y+answer[j].height);
        if ((x2>x1) && (y2>y1)) { 
            overlap = 100*(x2-x1)*(y2-y1)/(rectA.width*rectA.height);
            if (overlap > threshold) return 1;
            ////used for verification
            //cout << "x1=" << x1 <<  " y1=" << y1 << " x2=" << x2 << " y2=" << y2 <<"\n";
            //cout << faces_ans[i].width << " " << faces_ans[i].height << "\n";
            //cout << "overlap=" << overlap <<"\n"; 
            //putText(frame, "Face" , Point(x1,y1),1, 1, 255);
            //Point top_left( x1, y1);
            //Point bottom_right( x2, y2 );
            //rectangle(frame, top_left, bottom_right, 255, 1, 0);
        }
    }
    return 0;
}

void draw_rects(Mat *frame, std::vector<Rect> faces, int color, int thickness, int lineType){
    for( size_t i = 0; i < faces.size(); i++ )
        {
            Point top_left( faces[i].x, faces[i].y);
            Point bottom_right( faces[i].x + faces[i].width, faces[i].y + faces[i].height );
            rectangle(*frame, top_left, bottom_right, color, thickness, lineType);
            //cout << faces[i].x <<" "<<faces[i].y<<" "<< faces[i].x+faces[i].width<<" "<< faces[i].y+faces[i].height<<"\n"; 
        }
}
   
std::vector<String> getImageNames (void){
    std::vector<String> Ans;

    ifstream filestream;
    string filename;
    filename = test_data_folder + "/" + test_info;
    filestream.open(filename.c_str());
    if ( !filestream.is_open()){
        cout << "open failed" << endl;
        exit(1);
    }
    std::string line;
    std::string word
    while (getline(filestream, line)) {
        istringstream iss(line);
        iss >> word;    
        Ans.push_back(word);
    }
    filestream.close();
    return Ans;
}