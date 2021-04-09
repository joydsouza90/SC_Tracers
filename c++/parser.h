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
	        	if (token=="triangle")
			{
	        		continue;
			}

				if(token.c_str()[0]=='T')
					token="T";
				if(token.c_str()[0]=='D')
					token="D";

				if(token.c_str()[0]=='T' || token.c_str()[0]=='D')
				{
					assert(v.size() == 15 || v.size()==0);
					if(v.size()==0)
						break;

					Color* surfaceColor;
					Color* emissionColor;
					Vertex* v1 = new Vertex (v[0],v[1],v[2]);
					Vertex* v2 = new Vertex (v[3],v[4],v[5]);
					Vertex* v3 = new Vertex (v[6],v[7],v[8]);
					surfaceColor = new  Color (v[9],v[10],v[11], 1); 
					emissionColor = new Color(v[12],v[13],v[14],1);

					string tld_token = token;
					if(v[12]!=0)
						tld_token = "L";

					Triangle* tri = new Triangle(v1,v2,v3, tld_token);
					tri->setColor("surface", surfaceColor);
					tri->setColor("emission", emissionColor);
					triangles.push_back(tri);
					v.clear();
				
				  	continue;

				}
	        	v.push_back(std::stof(token));
   			}
  		}
  		return triangles;
	}


};
