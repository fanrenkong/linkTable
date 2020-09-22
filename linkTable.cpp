#include<stdio.h>
#include<stdlib.h>
typedef int elemType;
typedef struct linkTable{
	elemType data;
	struct linkTable *next;
}linkTable,*plt;
plt createFromHead(){
	//ͷ�����뷨��������
	plt header = (plt)malloc(sizeof(linkTable)),tmp;
	header->next = NULL;
	char status;
	printf("�Ƿ����Ԫ��(y/n):");
	scanf("%c",&status);
	while(status == 'y'){
		printf("������Ԫ�ص�ֵ:");
		tmp = (plt)malloc(sizeof(linkTable));
		scanf("%d",&tmp->data);
		tmp->next = header->next;
		header->next = tmp;
		getchar();//����������Ļس���
		printf("�Ƿ����Ԫ��(y/n):");
		scanf("%c",&status);
	}
	return header;//����ͷ�ڵ�
}
int list(plt header){
	plt ptr = header->next;
	int count = 0;
	if(header->next != NULL){
		printf("�����Ԫ��Ϊ:\n");
		while(ptr != NULL){
			count ++;
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}else{
		printf("���ȴ�������\n");
	}
	return count;
}
plt findCenter(plt header){
	//�ҵ��м�ڵ㣬���ÿ���ָ��ķ�ʽ������ָ���λ��һ���ǿ�ָ��λ�õ�һ��
	//���Ե���ָ������ȫ��Ԫ�غ���ָ���λ�þ����м�Ԫ�ص�λ��
	plt fast,slow;
	fast = slow = header;
	if(header->next !=NULL){
		while(fast->next !=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == NULL) break;
		}
	}else{
		printf("���ȴ�������\n");
		slow = slow->next;
	}
	return slow;
}
plt find(plt header,int index){
	//�������Ϊindex��Ԫ��
	int i;
	plt ptr = header;
	if(header->next != NULL){
		for(i=0;i<=index;i++) ptr = ptr->next;
	}else{
		printf("���ȴ�������\n");
		ptr = header->next;//NULL
	}
	return ptr;
}
int insertNode(plt header,int index,elemType data){
	//��ָ��λ�ò���ڵ㣬�ɹ�������ţ�ʧ�ܷ���-1
	plt ptr = header;
	int i;
	if(header->next != NULL){
		for(i=0;i<index;i++) ptr = ptr->next;//�ҵ�ָ��λ��Ԫ�ص�ǰһ���ڵ�
		plt new_Elem = (plt)malloc(sizeof(linkTable));
		new_Elem->data = data;
		new_Elem->next = ptr->next;
		ptr->next = new_Elem;
		return index;
	}else{
		printf("���ȴ�������\n");
		return -1;
	}
}
int delNode(plt header,int index){
	//ɾ��ָ����ŵĽڵ㣬ɾ���ɹ�����1���ڵ㲻���ڷ���-1������δ��������0
	if(header->next != NULL){
		int i;
		plt ptr = header,tmp;
		for(i=0;i<index;i++) ptr = ptr->next;
		tmp = ptr->next;//Ҫɾ���Ľڵ�
		ptr->next = ptr->next->next;//��������ɾ���ýڵ�
		free(tmp);//�ͷ��ڴ�ռ�
		return 1;
	}else{
		printf("���ȴ�������\n");
		return 0;
	}
}
int main(){
	plt header = createFromHead();
	int length = list(header);
	/*plt center = findCenter(header);
	if(length%2 == 0){
		printf("�м�ڵ���:%d��%d\n",center->data,center->next->data);
	}else{
		printf("�м�ڵ���:%d\n",center->data);
	}
	*/
	/*plt target = find(header,2);
	printf("����Ϊ2��Ԫ����:%d\n",target->data);*/
	/*insertNode(header,2,3);
	list(header);*/
	delNode(header,2);
	list(header);
	system("pause");
	return 0;
}