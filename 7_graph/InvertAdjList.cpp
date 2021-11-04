//
// Created by Jason Luo on 2021/11/2.
//

//#include "iostream"
//
///**
//* 邻接表法
//*/
//typedef int VertexType;
//
//#define MaxVertexNum 100    //图中顶点数目的最大值
//typedef struct ArcNode {    //边表节点
//    int adjVex;             //该弧所指向的顶点的位置
//    struct ArcNode *next;   //指向下一条弧的指针
//    //InfoType info;        //网的边权值
//} ArcNode;
//typedef struct VNode {      //顶点表结点
//    VertexType vertex;        //顶点信息
//    ArcNode *firstArc;         //指向第一条依附该顶点的弧的指针
//} VNode, AdjList[MaxVertexNum];                          //test
//typedef struct {
//    AdjList vertices;       //邻接表
//    int vexNum, arcNum;     //图的顶点数和弧数
//} ALGraph;                   //ALGraph是以邻接表存储的图类型
//
//// 逆置邻接表算法
//void InvertAdjList(AdjList Gin, AdjList Gout) {
//    int i = 0, n = 0, j = 0;
//    ArcNode *p = nullptr, *s = nullptr;
//    for (i = 1; i < n; i++) {
//        Gin[i].vertex = Gout[i].vertex;
//        Gin[i].firstArc = nullptr;
//    }
//    for (i = 1; i <= n; i++) {
//        p = Gout[i].firstArc;
//        while (p != nullptr) {
//            j = p->adjVex;
//            s = (ArcNode *) malloc(sizeof(ArcNode));
//            s->adjVex = i;
//            s->next = Gin[i].firstArc;
//            Gin[j].firstArc = s;
//            p = p->next;
//        }//while
//    }//for
//}//算法结朿

#include<iostream>

using namespace std;
#define  MaxNum 20                 //图的最大顶点数
#define MaxValue 65535               //最大值
// 定义边表结点
struct ArcNode {
    int adjvex;                   // 邻接点域
    ArcNode *next;                 //下一个邻接点
};
struct Graph {
    struct ArcNode *VertexNode[MaxNum];     //定义顶点表结点，⭐️全元素为指针的数组
    int VertextNum;                //顶点数量
    int EdgeNum;                   //边的数量
    //int Edge[MaxNum][MaxNum];      //存储边
};

void outAdjacency(Graph GM) {        //输出邻接表
    for (int i = 1; i <= GM.VertextNum; i++) {//定义顶点表结点
        ArcNode *B = new ArcNode;
        B = GM.VertexNode[i];
        cout << B->adjvex;
        B = B->next;
        while (B != nullptr) {
            cout << "->" << B->adjvex;
            B = B->next;
        }
        cout << "->Null" << endl;
    }
}

void Inverse_Adjacency(Graph GM) {        //输出反向邻接表
    Graph Inverse_GM;       //初始化图
    Inverse_GM.VertextNum = GM.VertextNum;//输入顶点数量
    Inverse_GM.EdgeNum = GM.EdgeNum;     //入边的数量
    for (int i = 1; i <= Inverse_GM.VertextNum; i++) {//定义顶点表结点
        ArcNode *A = new ArcNode;
        A->adjvex = i;
        A->next = nullptr;
        Inverse_GM.VertexNode[i] = A;
    }
    for (int i = 1; i <= GM.VertextNum; i++) {//定义顶点表结点
        ArcNode *B = new ArcNode;
        B = GM.VertexNode[i];
        B = B->next;
        while (B != nullptr) {
            ArcNode *A = new ArcNode;
            A->adjvex = i;  // ⭐️每次for循环搞一个顶点
            A->next = Inverse_GM.VertexNode[B->adjvex]->next; // ⭐️把转置表对应顶点的后面节点接A后面
            Inverse_GM.VertexNode[B->adjvex]->next = A; // ⭐️把A连到转置表上去
            B = B->next;
        }
    }
    cout << "输出反向邻接表" << endl;
    outAdjacency(Inverse_GM);
}

int main() {
    Graph GM;                     //初始化图
//    cin >> GM.VertextNum;           //输入顶点数量
//    cin >> GM.EdgeNum;              //入边的数量
    GM.VertextNum = 4;
    GM.EdgeNum = 5;
    for (int i = 1; i <= GM.VertextNum; i++) {//定义顶点表结点
        ArcNode *A = new ArcNode;
        A->adjvex = i;
        A->next = nullptr;
        GM.VertexNode[i] = A;
    }
//    for (int i = 1; i <= GM.EdgeNum; i++) {
//        int j, k;
//        cin >> j >> k;
//        ArcNode *A = new ArcNode;
//        A->adjvex = k;
//        A->next = GM.VertexNode[j]->next;
//        GM.VertexNode[j]->next = A;
//    }
    int j, k;
    j = 1;k = 4;
    ArcNode *A1 = new ArcNode;
    A1->adjvex = k;
    A1->next = GM.VertexNode[j]->next;
    GM.VertexNode[j]->next = A1;
    j = 4;k = 3;
    ArcNode *A2 = new ArcNode;
    A2->adjvex = k;
    A2->next = GM.VertexNode[j]->next;
    GM.VertexNode[j]->next = A2;
    j = 1;k = 2;
    ArcNode *A3 = new ArcNode;
    A3->adjvex = k;
    A3->next = GM.VertexNode[j]->next;
    GM.VertexNode[j]->next = A3;
    j = 2;k = 4;
    ArcNode *A4 = new ArcNode;
    A4->adjvex = k;
    A4->next = GM.VertexNode[j]->next;
    GM.VertexNode[j]->next = A4;
    j = 1;k = 3;
    ArcNode *A5 = new ArcNode;
    A5->adjvex = k;
    A5->next = GM.VertexNode[j]->next;
    GM.VertexNode[j]->next = A5;

    cout << "输出邻接表" << endl;
    outAdjacency(GM);              //输出邻接表
    Inverse_Adjacency(GM);         //反向邻接表
    return 0;
}