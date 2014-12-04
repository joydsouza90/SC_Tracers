#include <fstream>
#include <string>
#include "triangle.h"
#include "vertex.h"
#include "color.h"
using namespace std;
class Parser
{
public:
	string file_name;
	vector<Triangle*> triangles;
	ifstream fin;

	Parser(string f)
	{
		file_name = f;
	}

	vector<Triangle*> parse()
	{
		cout<<file_name.c_str()<<endl;
		fin.open("prism3.asc");
		cout<<"----------------"<<endl;
		if(fin.fail())
		{
			cout<<"Could not open file"<<endl;
			exit(1);
		}

		string buffer;
	    vector<float> v;
		while(!fin.eof())
		{
			getline(fin,buffer);
		    istringstream buf(buffer);
		    for(string token; getline(buf, token,' '); )
	        {
			cout<<token<<endl;
	        	if (token=="triangle")
			{
				cout<<"tri skip"<<endl;
	        		continue;
			}
				if(token=="T" || token=="D")
				{
					cout<<"T or D enter"<<endl;
					assert(v.size() == 15 || v.size()==0);
					if(v.size()==0)
						break;

					Color* surfaceColor;
					Color* emissionColor;
					Vertex* v1 = new Vertex (v[0],v[1],v[2]);
					cout<<"here"<<endl;
					Vertex* v2 = new Vertex (v[3],v[4],v[5]);
					Vertex* v3 = new Vertex (v[6],v[7],v[8]);
					cout<<"here"<<endl;
					surfaceColor = new  Color (v[9],v[10],v[11], 1); 
					emissionColor = new Color(v[12],v[13],v[14],1);
					cout<<"here"<<endl;

					string tld_token = ( v[12] != 0 ) ? "L" : token;
					cout<<"here"<<endl;

					Triangle* tri = new Triangle(v1,v2,v3, tld_token);
					cout<<"here"<<endl;
					tri->setColor("surface", surfaceColor);
					tri->setColor("emission", emissionColor);
					cout<<"here"<<endl;
					triangles.push_back(tri);
					v.clear();
					cout<<tri->token<<" is token"<<endl;
					cout<<"done"<<endl;
				
				  	continue;

				}
			cout<<"pushing back"<<endl;
	        	v.push_back(std::stof(token));
   			}
  		}
  		return triangles;
	}


};
