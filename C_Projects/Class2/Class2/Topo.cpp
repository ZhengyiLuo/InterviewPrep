#include<iostream>
using namespace std;

#define INFINITY 9999
#define MAX_VERTEX_NUM 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT   10

typedef int weight;
typedef int InfoType;
typedef int VertexType;
typedef int Status;
typedef int SElemType;

struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
};

typedef struct ArcCell{
	weight adj;
	InfoType *info;
}ArcCell, AdjMatrx[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct MGraph{
	VertexType vex[MAX_VERTEX_NUM];
	AdjMatrx arcs;
	int vexnum, arcnum;

};

typedef struct ArcNode{
	int adjvex;
	struct ArcNode * nextarc;
	InfoType *info;
};

typedef struct VNode{
	VertexType data;
	ArcNode * firstarc;
} AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
	AdjList vertices;
	int vexnum, arcnum;
};

typedef struct edges{
	VertexType adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];


int CreatUND(MGraph &G);
int CreatlinkedGraph(ALGraph &P, MGraph G);
int LocateVex(MGraph G, int v);
int NextAdjVex(ALGraph G, int v, int w);
int FirstAdjVex(ALGraph G, int v);
int VisitFunc(ALGraph G, int v);
void DFSTraverse(ALGraph G);
void DFS(ALGraph G, int v);
void MiniSpanTree_Prim(MGraph G, VertexType u);
int minimu(closedge closedge, int length);
int TopologicalSort(ALGraph G);
int FindInDegree(ALGraph G, int indegree[]);
int TopologicalSortCriticalPath(ALGraph G);
bool visited[MAX_VERTEX_NUM];
int indegree[MAX_VERTEX_NUM];
int accweight[MAX_VERTEX_NUM];
int accpoint[MAX_VERTEX_NUM];
int shortestPath(MGraph G, int v0, int Path[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int PathTable[MAX_VERTEX_NUM][MAX_VERTEX_NUM]);
Status InitStack(SqStack &S);
Status StackLength(SqStack S);
Status StackEmpty(SqStack S);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &);
Status StackTraverse(SqStack &S, Status(*visit)(SElemType));
Status GetTop(SqStack &S, SElemType &e);
Status visit(SElemType c);

int main(){

	MGraph G;
	ALGraph P;
	ArcNode *p;
	int i, j, k, v, w;
	//int Path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	//int PathTable[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


	CreatUND(G);
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			cout << G.arcs[i][j].adj << "\t";
		}
		cout << endl;
	}

	CreatlinkedGraph(P, G);
	cout << endl;
	cout<<endl;
	TopologicalSort(P);
	

	/*cout << endl;
	cout << endl;
	MiniSpanTree_Prim(G, 1);
*/
	//DFSTraverse(P);

	//for ( i = 0; i < P.vexnum; i++)
	//{
	//	v = i;
	//	for (w = FirstAdjVex(P, v); w != -1; w = NextAdjVex(P, v, w)){
	//		cout << P.vertices[w].data << "  ";

	//	}
	//	cout << endl;
	//}
	/*cout << endl;
	cout << endl;
	cout << endl;*/
	/*for (i = 0; i < P.vexnum; i++)
	{
		if (P.vertices[i].firstarc != NULL){
			p = P.vertices[i].firstarc;
			cout << P.vertices[i].data << "  the link is:";
			while (p != NULL)
			{
				cout << P.vertices[p->adjvex].data << "    ";
				p = p->nextarc;
			}
		}
		cout << endl;
	}*/

	//FindInDegree(P, indegree);
	//for ( i = 0; i < P.vexnum; i++)
	//{
	//	cout << indegree[i] << "   ";
	//}

	/*TopologicalSortCriticalPath(P);
	for ( i = 0; i < G.vexnum; i++)
	{
		cout << accpoint[i] << "  ";
	}

	cout << endl;

	for (i = 0; i < G.vexnum; i++)
	{
		cout << accweight[i] << "  ";
	}*/

	/*shortestPath(G, 0, Path, PathTable);
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			cout <<Path[i][j]  << "\t";
		}
		cout << endl;
	}*/
	

	system("pause");

}

int CreatlinkedGraph(ALGraph &P, MGraph G){
	int i, j, k, w, count = 0;
	int v1, v2;
	ArcNode *arc, *store = NULL;
	P.vexnum = G.vexnum;
	P.arcnum = G.arcnum;


	for (i = 0; i < G.vexnum; i++){
		P.vertices[i].data = G.vex[i];
	}
	for (i = 0; i < G.vexnum; i++)
	{
		count = 0;
		arc = new ArcNode;
		P.vertices[i].firstarc = arc;
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[i][j].adj != INFINITY){
				arc->nextarc = new ArcNode;
				arc->info = new int;
				arc->adjvex = j;
				*(arc->info) = G.arcs[i][j].adj;
				store = arc;
				count++;
				arc = arc->nextarc;
			}

		}
		store->nextarc = NULL;
		if (count == 0)
		{
			P.vertices[i].firstarc = NULL;
		}
	}


	return 0;
}

int CreatUND(MGraph &G){
	int i, j, k, w;
	int v1, v2;

	cout << "Please enter the nuber of vexes" << endl;
	cin >> G.vexnum;
	cout << "please enter the number of arcnums" << endl;
	cin >> G.arcnum;
	for (i = 0; i < G.vexnum; i++){
		cout << "Please enter the vexes" << endl;
		cin >> G.vex[i];
	}
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = { INFINITY, NULL };
		}
	}
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "Please enter v1" << endl;
		cin >> v1;
		cout << "please enter v2" << endl;
		cin >> v2;
		cout << "please enter weight" << endl;
		cin >> w;

		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
	}

	return 0;
}

int LocateVex(MGraph G, int v){
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (G.vex[i] == v)
			return i;
	return 0;
}

int NextAdjVex(ALGraph G, int v, int w){
	ArcNode *p = NULL;
	p = G.vertices[v].firstarc;
	while (p->nextarc){
		if (p->adjvex == w)
		{
			return p->nextarc->adjvex;
		}
		p = p->nextarc;
	}
	return -1;

}

int FirstAdjVex(ALGraph G, int v){
	if (G.vertices[v].firstarc)
		return G.vertices[v].firstarc->adjvex;
	else return -1;
}

int VisitFunc(ALGraph G, int v){
	cout << G.vertices[v].data << endl;
	return 0;
}

void DFSTraverse(ALGraph G){
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
	}
	DFS(G, 3);
}

void DFS(ALGraph G, int v){
	int w;
	visited[v] = true;
	VisitFunc(G, v);
	for (w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w)){
		if (!visited[w]) DFS(G, w);
	}


}

void MiniSpanTree_Prim(MGraph G, VertexType u){
	int k, j, i;
	closedge closedge;
	k = LocateVex(G, u);
	for (j = 0; j < G.vexnum; j++){
		if (j != k)
			closedge[j] = { u, G.arcs[k][j].adj };
		else closedge[j].lowcost = 0;
	}
	closedge[k].lowcost = 0;
	for (i = 0; i < G.vexnum; i++)
	{
		k = minimu(closedge, G.vexnum);
		if (k == -1) break;
		cout << closedge[k].adjvex << " -> " << G.vex[k] << endl;
		closedge[k].lowcost = 0;
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[k][j].adj<closedge[j].lowcost)
			{
				closedge[j] = { G.vex[k], G.arcs[k][j].adj };
			}
		}
	}


}

int minimu(closedge closedge, int length){
	int i, j, min, store = -1;
	min = INFINITY;
	for (i = 0; i < length; i++)
	{
		if (closedge[i].lowcost != 0 && min > closedge[i].lowcost){
			min = closedge[i].lowcost;
			store = i;
		}
	}
	return store;
}

int TopologicalSort(ALGraph G){
	SqStack S;
	ArcNode *p;
	int i, count,k ;
	FindInDegree(G, indegree);
	InitStack(S);
	for ( i = 0; i < G.vexnum; i++)
	{
		if (!indegree[i]) Push(S, i);
	}
	count = 0;
	while (!StackEmpty(S)){
		Pop(S, i);
		cout << G.vertices[i].data;
		for (p = G.vertices[i].firstarc; p; p=p->nextarc)
		{
			k = p->adjvex;
			if (!(--indegree[k])) Push(S, k);
		}

	}

	return 0;
}

int FindInDegree(ALGraph G, int indegree[]){
	int i,j, count = 0;
	ArcNode *p;
	for ( i = 0; i < G.vexnum; i++)
	{
		count = 0;

		for (j = 0; j < G.vexnum; j++)
		{
			p = G.vertices[j].firstarc;
			while (p){
				if (p->adjvex == i){
					count++;
				}
				p = p->nextarc;
			}
		}
		indegree[i] = count;
	}
	return 0;
}

Status InitStack(SqStack &S){

	S.base = new SElemType;
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &S, SElemType e){
	if (S.top - S.base >= S.stacksize){
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;

}

Status Pop(SqStack &S, SElemType &e){
	if (S.top == S.base)return ERROR;
	e = *--S.top;
	return OK;
}

Status StackTraverse(SqStack &S, Status(*visit)(SElemType)){
	if (S.base == S.top) cout << "Empty Stack" << endl;
	while (S.top>S.base)
		visit(*S.base++);

	return OK;
}

Status visit(SElemType c)
{
	cout << c << endl;
	return OK;
}

Status StackEmpty(SqStack S){
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

Status GetTop(SqStack &S, SElemType &e){
	if (S.top>S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}

int TopologicalSortCriticalPath(ALGraph G){
	SqStack S;
	ArcNode *p;
	int i, count, k;
	for ( i = 0; i < G.vexnum; i++)
	{
		accweight[i] = 0;
		accpoint[i] = 0;
	}
	FindInDegree(G, indegree);
	InitStack(S);
	for (i = 0; i < G.vexnum; i++)
	{
		if (!indegree[i]) Push(S, i);
	}
	count = 0;
	while (!StackEmpty(S)){
		Pop(S, i);
		cout << G.vertices[i].data<<"  ";
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			if (!(--indegree[k])) Push(S, k);
			if (accweight[i] + *(p->info) > accweight[k]) {
				accweight[k] = accweight[i] + *(p->info);
				accpoint[i] = 1;
			}
		}

	}
	cout << endl;
	cout << endl;
	return 0;


}

int shortestPath(MGraph G, int v0, int P[MAX_VERTEX_NUM][MAX_VERTEX_NUM], int D[MAX_VERTEX_NUM]){
	bool final[MAX_VERTEX_NUM];
	int i, w, min, v, j;
	for ( i = 0; i < G.vexnum; i++)
	{
		final[i] = false;
		D[i] = G.arcs[v0][i].adj;
		for ( w = 0; w < G.vexnum; w++)
		{
			P[i][w] = false;
		}
		if (D[i] < INFINITY){
			P[i][v0] = true;
			//P[i][i] = true;
		}
	}
	D[v0] = 0;
	final[v0] = true;

	for ( i = 0; i < G.vexnum; i++)
	{
		min = INFINITY;
		for (w = 0; w < G.vexnum; w++)
			if (!final[w])
				if (D[w] < min)
				{
					v = w;
					min = D[w];
				}
		final[v] = true;
		for ( w = 0; w < G.vexnum; w++)
		{
			if (!final[w]&&(min +G.arcs[v][w].adj)<D[w])
			{
				D[w] = min + G.arcs[v][w].adj;
				
				for ( j = 0; j < G.vexnum; j++)
				{
					P[w][j] = P[v][j];
				}
				P[w][v] = w;
			}
		}
	}
	return 0;
}