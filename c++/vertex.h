class Vertex
{
public:
	float x;
	float y;
	float z;

	Vertex(float a,float b,float c)
	{
		x=a;
		y=b;
		z=c;
	}

	Vertex()
	{}

	Vertex sub(Vertex other)
	{
		Vertex v;
		v.x=x-other.x;
		v.y=y-other.y;
		v.z=z-other.z;
		return v;
	}

	Vertex cross(Vertex other)
	{
		Vertex v;
		v.x=y * other.z - z*other.y;
		v.y=z * other.x - x*other.z;
		v.z=x * other.y - y*other.x;
		return v;
	}

	float dot(Vertex other)
	{
		return x*other.x+y*other.y+z*other.z;
	}

	float scale(float s)
	{
		return x*s+y*s+z*s;
	}

	Vertex mul(Vertex other)
	{
		Vertex v;
		v.x=x*other.x;
		v.y=y*other.y;
		v.z=z*other.z;
		return v;
	}

};