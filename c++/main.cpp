#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <assert.h>
using namespace std;

#include "vertex.h"
#include "triangle.h"
#include "parser.h"
#include "diamond.h"


int main()
{
	Parser* p = new Parser("diamond_trans.asc");
	Diamond d = Diamond(p->parse());
}