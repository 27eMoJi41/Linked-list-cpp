#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	node * next;
};

node * add(node * r,int x){
	node * iter = r;
	if(r!=NULL){		
		while(iter->next!=NULL){
			iter = iter->next;
		}
		iter->next =(node*)malloc(sizeof(node));
		iter->next->data = x;
		iter->next->next = NULL;
		return r;
	}
	else{
		iter = (node*)malloc(sizeof(node));
		iter->data = x;
		iter->next = NULL;
		return r;
	}

}

void print(node * r){
	while(r != NULL){
		printf("%d ",r->data);
		r= r->next;
	}
	printf("\n");
}

node * add_in_order(node * r,int x){
	if(r==NULL){
		r = (node*)malloc(sizeof(node));
		r->data = x;
		r->next = NULL;
		return r;
	}
 
	if(r->data>x){
		node * temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->next = r;
		return temp;
	}
	node * iter1 = r;
	node * iter2 = r;
	while(iter1->next != NULL){
		iter1 = iter1->next;
	}
	if(iter1->data<x){
		iter1 = add(iter1,x);
		return r;
	}
	while(iter2->next->data<x && iter2->next != NULL){
		iter2=iter2->next;
	}
	node * temp = (node*)malloc(sizeof(node));
	temp->next = iter2->next;
	iter2->next = temp;
	temp->data = x;
	return r;
}
node * extract(node * r,int x){
	node * iter = r;
	node * temp;
	if(r->data == x){
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}
	while(iter->next !=NULL && iter->next->data != x){
		iter=iter->next;
	}
	if(iter->next == NULL){
		printf("undefined number");
		printf("\n");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;
}

int main(){
	node * root = (node*)malloc(sizeof(node));
	root = NULL;
	root = add_in_order(root,4);
	root = add_in_order(root,2);
	root = add_in_order(root,3);
	root = add_in_order(root,1);
	print(root);
	root = add_in_order(root,5);
	print(root);
	root = extract(root,5);
	root = extract(root,6);
	print(root);
	root = extract(root,1);
	print(root);
	root = add(root,75); 
	print(root);	
}
