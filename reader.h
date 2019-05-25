#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class reader {
    public:
        pair<float,float> res;
        map<string,float> camInfo; //px py pz tx ty tz ux uy uz fov f
        map<string,map<string,float>> materialInfo; //name r g b kd ks ke alpha
        map<string,float> material;
        vector<map<string,float>> objectsInfo; // cx cy cz r red green blue kd ks ke alpha
        map<string,float> object;

        reader(){
            string s, materialName;
            float px, py, pz, tx, ty, tz, ux, uy, uz, fov, f;
            float  r, g, b, kd, ks, ke, alpha;
            float cx, cy, cz, raio;
            while (!cin.eof()) {
                cin >> s;
                if(s == "res"){
                    cin >> res.first >> res.second;
                }else if (s == "camera"){
                    cin >> px >> py >> pz >> tx >> ty >> tz >> ux >> uy >> uz >> fov >> f;
                    camInfo.insert({"px",px});
                    camInfo.insert({"py",py});
                    camInfo.insert({"pz",pz});
                    camInfo.insert({"tx",tx});
                    camInfo.insert({"ty",ty});
                    camInfo.insert({"tz",tz});
                    camInfo.insert({"ux",ux});
                    camInfo.insert({"uy",uy});
                    camInfo.insert({"uz",uz});
                    camInfo.insert({"fov",fov});
                    camInfo.insert({"f",f});
                }else if (s == "material"){
                    cin >> materialName >> r >> g >> b >> kd >> ks >> ke >> alpha;
                    material.insert({"r",r});
                    material.insert({"g",g});
                    material.insert({"b",b});
                    material.insert({"kd",kd});
                    material.insert({"ks",ks});
                    material.insert({"ke",ke});
                    material.insert({"alpha",alpha});
                    materialInfo.insert({materialName,material});                        
                }else if (s == "sphere"){
                    cin >> cx >> cy >> cz >> raio >> materialName;
                    material = materialInfo.at(materialName);
                    object.insert({"cx",cx});
                    object.insert({"cy",cy});
                    object.insert({"cz",cz});
                    object.insert({"raio",raio});                        
                    object.insert({"r",material.at("r")});
                    object.insert({"g",material.at("g")});
                    object.insert({"b",material.at("b")});
                    object.insert({"kd",material.at("kd")});
                    object.insert({"ks",material.at("ks")});
                    object.insert({"ke",material.at("ke")});
                    object.insert({"alpha",material.at("alpha")});
                    objectsInfo.push_back(object);
                }


            }   
        }          
            
    
};