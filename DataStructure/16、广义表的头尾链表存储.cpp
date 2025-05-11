#include "结构、常量定义及函数声明.h"

//1、求广义表的深度
int GListDepth16(GList L)
{   // 采用头尾链表存储结构,求广义表L的深度。
    if (!L) return 1;    //空表深度为1
    if (L->tag == ATOM)   return 0;  //原子深度为0
    int max,dep = 0;
	GList pp = L; //pp指向表头结点
    for (max = 0, pp = L; pp; pp = pp->ptr.tp) {
        dep = GListDepth16(pp->ptr.hp); //求以pp->ptr.hp为头指针的子表深度（递归）
            if (dep > max)   max = dep;
    }
    return max + 1;   //非空表的深度是各元素的深度的最大值加1
}// GListDepth

//2、求广义表的长度
int GListLength16(GList L)
{ //求广义表L的长度（非递归）,即元素个数
    int len = 0;
    GList p;
    if (L->tag == LIST && !L->ptr.hp)   return 0;   // 空表返回0
    else if (L->tag == ATOM) return 1;              // 单原子表
    else {                                          // 一般表
        p = L->ptr.hp;
        do
        {
            len++;
            p = p->ptr.tp;
        } while (p);
        return len;
    }
}

//3、求广义表的长度（递归版）
int LengthRecur16(GLNode* GL) {
    if (GL == NULL) return 0; //广义表为空时
    else return 1 + LengthRecur16(GL->ptr.tp); //长度为表尾的长度+1
}

//打印广义表
void printGList16(GList L) {
	if (L == NULL) return; //空表
	if (L->tag == ATOM) { //原子结点
		printf("%d ", L->atom);
	}
	else { //表结点
		printf("(");
		printGList16(L->ptr.hp); //打印表头
		printf(")");
		if (L->ptr.tp != NULL) { //打印表尾
			printf(",");
			printGList16(L->ptr.tp);
		}
	}
}
