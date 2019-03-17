#include "ofMain.h"
#include <vector>

using namespace std;

class StrangeAttractor{
    public:
        ofMesh mesh;
        vector<ofVec2f> pt;
        ofVec2f r;
        float w;
        float h;
        StrangeAttractor(int n){
            w = 800;
            h = 800;
            for(int i=0;i<n;i++){
                ofVec2f v(ofRandom(w),ofRandom(h));
                pt.push_back(v);
            }
            r.x = ofRandom(w);
            r.y = ofRandom(h);

        }
        void set_triangle(){
            pt.clear();
            pt.push_back(ofVec2f(w/2,0));
            pt.push_back(ofVec2f(0,h));
            pt.push_back(ofVec2f(w,h));
        }
        void set_square(){
            pt.clear();
            pt.push_back(ofVec2f(0,0));
            pt.push_back(ofVec2f(w,0));
            pt.push_back(ofVec2f(w,h));
            pt.push_back(ofVec2f(0,h));
        }
        void set_polygon(int n){
            pt.clear();
            int xo = w/2;
            int yo = h/2;
            int r = w/2;
            for(float i=0;i<=2*PI;i+=2*PI/n){
                pt.push_back(ofVec2f(xo+r*cos(i),yo+r*sin(i)));
            }
        }
        ofVec2f play(){
            ofVec2f p;
            int i = (int)ofRandom(pt.size());
            p.x = (pt[i].x + r.x)/2;
            p.y = (pt[i].y + r.y)/2;
            r = p;
            return p;
        }
};
