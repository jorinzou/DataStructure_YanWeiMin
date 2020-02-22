//源码地址:https://www.geeksforgeeks.org/cuckoo-hashing/

/*
插入过程分析
1.hash[0]的位置9插入元素20  
place调用次数1

2.hash[0]的位置6插入元素50  
place调用次数1

3.插入元素53,与hash[0]中的元素20位置9产生碰撞,踢出元素20，hash[0]的位置9插入元素53,
递归调用place一次，最后元素20插入hash[1]的位置1    
place调用次数2

4.插入元素75,与hash[0]中的元素53位置9产生碰撞，踢出53，hash[0]的位置9插入75，
递归调用place一次，最后元素53插入hash[1]的位置4    
place调用次数2

5.插入元素100,没有碰撞，直接插入hash[0]的位置1   
place调用次数1

6.插入元素67,与hash[0]中的元素100位置1产生碰撞，踢出100，hash[0]的位置1插入67，
递归调用place一次，在hash[1]的位置9插入元素100    
place调用次数2

7.插入元素105，与hash[0]的元素50在位置6产生碰撞，踢出50,hash[0]的位置6插入105，
递归调用place一次，在hash[1]的位置4与53产生碰撞，踢出53，hash[1]的位置4插入50,
递归调用place,53在hash[0]找位置，与75的位置9产生碰撞，踢出75，hash[0]的位置9插入53
递归调用place，75在hash[1]的位置6找到坑插入    
place调用次数4

8.插入元素3    
place调用次数1

9.插入元素36,与hash[0]的元素3在位置3产生碰撞，踢出3，hash[0]的位置3插入36,
递归调用place，最后元素3在hash[1]的位置0找到坑插入    
place调用次数2

10.插入39，在hash[0]的位置6与105产生碰撞，踢出105，hash[0]的位置6插入39,
递归调用place，105在hash[1]的位置9与100产生碰撞，踢出100，hash[1]的位置9插入105
递归调用place，100与hash[0]的位置1与67产生碰撞，踢出67，hash[0]的位置1插入100
递归调用place，67与hash[1]的位置6的75产生碰撞，踢出75，hash[1]的位置6插入67
递归调用place，75与hash[0]的位置9与53产生碰撞，踢出53,hash[0]的位置9插入75
递归调用place，53与hash[1]的位置4的50产生碰撞，踢出50，hash[1]的位置4插入53
递归调用place，50与hash[0]的位置6与39产生碰撞，踢出39,hash[0]的位置6插入50
递归调用place，39在hash[1]中找到坑3，终于可以插入完毕     place调用次数8

place一共调用:24次
*/


// C++ program to demonstrate working of Cuckoo 
// hashing. 
#include<bits/stdc++.h> 

// upper bound on number of elements in our set 
#define MAXN 11 

// choices for position 
#define ver 2 

#define DEBUG_INFO(fmt, args...) printf("\033[33m[%s:%s:%d]\033[0m "#fmt"\r\n", __FILE__,__FUNCTION__, __LINE__, ##args)

// Auxiliary space bounded by a small multiple 
// of MAXN, minimizing wastage 
int hashtable[ver][MAXN]; //int hashtable[2][11]; 

// Array to store possible positions for a key 
int pos[ver]; //int pos[2];

/* function to fill hash table with dummy value 
* dummy value: INT_MIN 
* number of hashtables: ver */
void initTable() 
{ 
	for (int j=0; j<MAXN; j++) 
		for (int i=0; i<ver; i++) 
			hashtable[i][j] = INT_MIN; 
} 

/* return hashed value for a key 
* function: ID of hash function according to which 
	key has to hashed 
* key: item to be hashed */
int hash(int function, int key) 
{ 
	switch (function) 
	{ 
		case 1: return key%MAXN; //11   
		case 2: return (key/MAXN)%MAXN; //11
	} 
} 

/* function to place a key in one of its possible positions 
* tableID: table in which key has to be placed, also equal 
to function according to which key must be hashed 
* cnt: number of times function has already been called 
in order to place the first input key 
* n: maximum number of times function can be recursively 
called before stopping and declaring presence of cycle */
static int place_cnt = 0;
void place(int key, int tableID, int cnt, int n) //keys[i], 0, cnt, n
{ 
	place_cnt++;
	/* if function has been recursively called max number 
	of times, stop and declare cycle. Rehash. */
	if (cnt==n) 
	{ 
		printf("%d unpositioned\n", key); 
		printf("Cycle present. REHASH.\n"); 
		return; 
	} 

	/* calculate and store possible positions for the key. 
	* check if key already present at any of the positions. 
	If YES, return. */
	for (int i=0; i<ver; i++) 
	{ //判断哈希表是的位置是否空
		pos[i] = hash(i+1, key); 
		if (hashtable[i][pos[i]] == key) //这个位置的数据已经插入
		return; 
	} 

	/* check if another key is already present at the 
	position for the new key in the table 
	* If YES: place the new key in its position 
	* and place the older key in an alternate position 
	for it in the next table */
	if (hashtable[tableID][pos[tableID]]!=INT_MIN) 
	{ 
		//产生碰撞，把旧的元素踢出，递归插入另一张哈希表
		int dis = hashtable[tableID][pos[tableID]]; 
		hashtable[tableID][pos[tableID]] = key; 
		place(dis, (tableID+1)%ver, cnt+1, n); 
	} 
	else //else: place the new key in its position 
	hashtable[tableID][pos[tableID]] = key; 
} 

/* function to print hash table contents */
void printTable() 
{ 
	printf("Final hash tables:\n"); 

	for (int i=0; i<ver; i++, printf("\n")) 
		for (int j=0; j<MAXN; j++) 
			(hashtable[i][j]==INT_MIN)? printf("- "): 
					printf("%d ", hashtable[i][j]); 

	printf("\n"); 
} 

/* function for Cuckoo-hashing keys 
* keys[]: input array of keys 
* n: size of input array */
void cuckoo(int keys[], int n) 
{ 
	// initialize hash tables to a dummy value (INT-MIN) 
	// indicating empty position 
	initTable(); 

	// start with placing every key at its position in 
	// the first hash table according to first hash 
	// function 
	for (int i=0, cnt=0; i<n; i++, cnt=0) 
		place(keys[i], 0, cnt, n); 

	//print the final hash tables 
	//printTable(); 
} 

/* driver function */
int main() 
{ 

	//DEBUG_INFO("INT_MIN=%d",INT_MIN);
	/* following array doesn't have any cycles and 
	hence all keys will be inserted without any 
	rehashing */
	int keys_1[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};//10
					 
	int n = sizeof(keys_1)/sizeof(int); 
	//DEBUG_INFO("n=%d",n);

	cuckoo(keys_1, n/*10*/); 
	DEBUG_INFO("place_cnt=%d\n",place_cnt);
	//打印看看，与分析的是否一致
	printf("%d,%d,%d,%d\n",hashtable[0][1],hashtable[0][3],hashtable[0][6],hashtable[0][9]);
	printf("%d,%d,%d,%d,%d,%d\n",hashtable[1][0],hashtable[1][1],hashtable[1][3],hashtable[1][4],hashtable[1][6],hashtable[1][9]);

	#if 0
	/* following array has a cycle and hence we will 
	have to rehash to position every key */
	//增加多一个数据6
	//当插入6时，循环整个过程，105没有位置，要重新rehash，比如增加一行，哈希表就变成三行11列,原来是二行10列，增加一行之后，元素分布就会变得稀疏，需要更多的内存
	int keys_2[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6}; 

	int m = sizeof(keys_2)/sizeof(int); 
	//DEBUG_INFO("m=%d",m);

	cuckoo(keys_2, m); 
	#endif

	return 0; 
} 
