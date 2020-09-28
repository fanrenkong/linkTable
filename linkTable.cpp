#include<stdio.h>
#include<stdlib.h>
typedef int elemType;
typedef struct linkTable{
	elemType data;
	struct linkTable *next;
}linkTable,*plt;
plt createFromHead(){
	//头部插入法创建链表
	plt header = (plt)malloc(sizeof(linkTable)),tmp;
	header->next = NULL;
	char status;
	printf("是否插入元素(y/n):");
	scanf("%c",&status);
	while(status == 'y'){
		printf("请输入元素的值:");
		tmp = (plt)malloc(sizeof(linkTable));
		scanf("%d",&tmp->data);
		tmp->next = header->next;
		header->next = tmp;
		getchar();//清除缓存区的回车符
		printf("是否插入元素(y/n):");
		scanf("%c",&status);
	}
	return header;//返回头节点
}
int list(plt header){
	plt ptr = header->next;
	int count = 0;
	if(header->next != NULL){
		printf("链表的元素为:\n");
		while(ptr != NULL){
			count ++;
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}else{
		printf("请先创建链表！\n");
	}
	return count;
}
plt findCenter(plt header){
	//找到中间节点，采用快慢指针的方式，当慢指针的位置一定是快指针位置的一半
	//所以当快指针走完全部元素后，慢指针的位置就是中间元素的位置
	plt fast,slow;
	fast = slow = header;
	if(header->next != NULL){
		while(fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == NULL) break;
		}
	}else{
		printf("请先创建链表！\n");
		slow = slow->next;
	}
	return slow;
}
plt find(plt header,int index){
	//查找序号为index的元素
	int i;
	plt ptr = header;
	if(header->next != NULL){
		for(i=0;i<=index;i++) ptr = ptr->next;
	}else{
		printf("请先创建链表！\n");
		ptr = header->next;//NULL
	}
	return ptr;
}
int insertNode(plt header,int index,elemType data){
	//在指定位置插入节点，成功返回序号，失败返回-1
	plt ptr = header;
	int i;
	if(header->next != NULL){
		for(i=0;i<index;i++) ptr = ptr->next;//找到指定位置元素的前一个节点
		plt new_Elem = (plt)malloc(sizeof(linkTable));
		new_Elem->data = data;
		new_Elem->next = ptr->next;
		ptr->next = new_Elem;
		return index;
	}else{
		printf("请先创建链表！\n");
		return -1;
	}
}
int delNode(plt header,int index){
	//删除指定序号的节点，删除成功返回1，节点不存在返回-1，链表未创建返回0
	if(header->next != NULL){
		int i;
		plt ptr = header,tmp;
		for(i=0;i<index;i++) ptr = ptr->next;
		tmp = ptr->next;//要删除的节点
		ptr->next = ptr->next->next;//从链表中删除该节点
		free(tmp);//释放内存空间
		return 1;
	}else{
		printf("请先创建链表！\n");
		return 0;
	}
}
int main(){
	plt header = createFromHead();
	int length = list(header);
	plt center = findCenter(header);
	if(length%2 == 0){
		printf("中间节点是:%d和%d\n",center->data,center->next->data);
	}else{
		printf("中间节点是:%d\n",center->data);
	}
	/*plt target = find(header,2);
	printf("索引为2的元素是:%d\n",target->data);*/
	/*insertNode(header,2,3);
	list(header);*/
	delNode(header,2);
	list(header);
	system("pause");
	return 0;
}
