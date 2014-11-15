
class Parser
{
public:
	string file_name;
	vector<Triangle> triangles;
	ifstream fin;

	Parser(string f)
	{
		file_name = f;
	}

	vector<Triangle> parse()
	{
		fin.open(file_name);
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
	        		continue;

				if(token=="T" || token=="D")
				{
					assert(v.size()>=9 || v.size()==0);
					if(v.size()==0)
						break;

					Vertex v1,v2,v3;

					v1 = Vertex (v[0],v[1],v[2]);
					v2 = Vertex (v[3],v[4],v[5]);
					v3 = Vertex (v[6],v[7],v[8]);

					Triangle tri = Triangle(v1,v2,v3);
					triangles.push_back(tri);

//					Vertex origin= Vertex(0,0,0);
//					Vertex dir= Vertex(1,2,3);
//					tri.intersection(origin,dir);
//					cout<<tri.t<<" is t "<<tri.inter<<" is inter"<<endl;

					v.clear();
				  	continue;
				}
	        	v.push_back(stof(token));
   			}
  		}
  		return triangles;
	}


};