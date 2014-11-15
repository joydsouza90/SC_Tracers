class Triangle
{
public:	
	Vertex v1;
	Vertex v2;
	Vertex v3;
	Vertex edge1;
	Vertex edge2;
	Vertex norm;
	float t; //output of intersection
	bool inter; // same

	Triangle(Vertex a,Vertex b,Vertex c)
	{
		v1=a;
		v2=b;
		v3=c;
		computeNormal();
	}

	void computeNormal()
	{
		edge1 = v2.sub(v1);
		edge2 = v3.sub(v1);
		norm = edge1.cross(edge2);
	}

	void print()
	{
		cout<<"Vertex 1: "<<v1.x<<" "<<v1.y<<" "<<v1.z<<endl;
		cout<<"Vertex 2: "<<v2.x<<" "<<v2.y<<" "<<v2.z<<endl;
		cout<<"Vertex 3: "<<v3.x<<" "<<v3.y<<" "<<v3.z<<endl;
		cout<<"Normal : "<<norm.x<<" "<<norm.y<<" "<<norm.z<<endl;

	}

	void intersection(Vertex origin, Vertex dir)
	{
		float det=edge1.dot(norm);
		if(det==0)
		{
			inter=false;
			t=0;
			return;
		}

		float invDet=1/det;
		Vertex tvec=origin.sub(v1);
		float u=(tvec.mul(norm)).scale(invDet);

		if(u<0 || u>1)
		{
			inter=false;
			t=0;
			return;
		}

		Vertex qvec = tvec.cross(edge1);
		float v = dir.mul(qvec).scale(invDet);

		if (v<0||v+u>1)
        {
        	inter = false; 
        	t = 0; 
        	return;
        }

        inter = true;
        t = (edge2.mul(qvec)).scale(invDet);
	}


};