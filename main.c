#include <stdio.h>

typedef struct {
    int length;
    int data[100];
} SqList;

typedef int ElementType;
typedef enum {
    ERROR = -1,
    OK = 0
}Status;

/*
    插入操作
   （1）如果插入位置不合理，抛出异常；
   （2）如果线性表长度大于等于数组长度，则抛出异常或动态增加容量；
   （3）从最后一个元素开始向前遍历到第个位置，分别将它们都向后移动一个位置；
   （4）将要插入元素填入位置处；
   （5）表长加1。
*/ 
    Status ListInsert(SqList* L, int i, ElementType* e) {
        if (L->length == 100) {
            return ERROR; // 表满，无法插入
        }

        if (i < 1 || i > L->length + 1) {
            return ERROR; // 参数i不合法
        }

        if (i <= L->length) {
            for (int k = L->length - 1; k >= i - 1; k--) {
                L->data[k + 1] = L->data[k]; // 元素后移一位
            }
            L->data[i - 1] = e; // 插入新元素
        }
        else {
            // 当i等于L->length +1时，直接在表尾插入
            L->data[L->length] = e;
        }

        L->length++;
        return OK;
    }
/*
    查找操作
    对于线性表的顺序存储结构来说，如果我们要实现GetElem操作，即将线性表L中的
    第个位置元素值返回，只要的数值在数组下标范围内，就是把数组第1下标的值返回即可
*/ 
Status GetElem(SqList L, int i, ElementType* e) {
	// 检查顺序表是否为空，或者索引i是否无效（小于1或大于顺序表长度）
	if (L.length == 0 || i < 1 || i > L.length) {
		return ERROR;  // 如果无效，返回错误
	}
	// 获取顺序表中第i个元素并赋值给指针e
	*e = L.data[i - 1];  // 注意L.data是从0开始，所以用i-1
	return OK;  // 返回成功
}

/*
    删除操作
    （1）如果删除位置不合理，抛出异常；
    （2）取出删除元素；
    （3）从册除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置；
    （4）表长减1。
*/
Status delete(SqList* L, int i, ElementType* e) {
    // 如果顺序表为空，无法删除
    if (L->length == 0) {
        return ERROR;
    }
    // 检查索引是否有效
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    // 获取要删除的元素
    *e = L->data[i - 1];
    // 如果要删除的是不是最后一个元素，移动元素
    for (int k = i; k < L->length; k++) {
        L->data[k - 1] = L->data[k];  // 向前移动元素
    }
    // 减少顺序表的长度
    L->length--;
    return OK;
}

int main() {
    // 定义一个顺序表 list，它的数据类型是 SqList
    SqList list;
    // 设置顺序表的长度为 0
    list.length = 0;
    int j = 10;
    for (int i = 0; i < j; i++) {
        int e = 20 + i;
        /*
            调用 ListInsert 函数将元素 e 插入到顺序表 list 的第 1 个位置。
            &list 表示传递 list 的地址，因此对 list 的修改会影响到实际的顺序表。
            返回的 Status 存储插入操作的结果（可能是 OK 或 ERROR）。
        */
        Status result = ListInsert(&list, 1, e);
        if (result == OK) {
            printf("插入后的长度%d\n", list.length);
        }
        else {
            printf("插入失败");
        }
    }

    // 定义一个 ElementType 类型的变量 e 用来存储从顺序表中获取的元素
    ElementType e;
    // 调用 GetElem 函数，从顺序表 list 的第 1 个位置获取元素，并将该元素存储到 e 中
    Status get = GetElem(list, 1, &e);
    for (int k = 0; k < list.length; k++) {
        //printf("总共有%d个元素\n", list.length);
        printf("%d元素\n", list.data[k]);
    }
    printf("总共有%d个元素\n", list.length);
   
    // 删除操作
    Status dele = delete(&list, 1, &e);
    if (dele == OK) {
        printf("删除的元素是%d\n", e);
        printf("删除后的列表长度%d\n", list.length);
        printf("删除后的列表顺序");
        for (int j = 0; j < list.length; j++) {
            printf("%d,",list.data[j]);
        }
    }
}