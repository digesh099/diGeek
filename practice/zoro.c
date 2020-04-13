#include<stdio.h>
#include<stdint.h>
int arr[1000005] = {0};

// get the number of chocolate from the ID
// 10 : 1,2,5,10 = 17
// 4 : 1,2,4 = 6
// 3 : 1,3 = 3
// 7 : 1,7 = 7
// 50 : 1,2,5,10,25,50 = 92
// 2 : 1,2 = 2
// 5 : 1,5 = 5
// 21 : 1, 3, 7, 21 = 31
// 6 : 1,2,3,6 = 11
// 34 : 1,2,17,34 = 53
int numOfChocolates(int id)
{
    int i = 0;
    int num = id;
    for (i = 2; i < id; i++)
    {
        if(0 == id%i)
        {
            num = num + i;
        }
    }

    if(num > 1000003)
    {
        return num%1000003;
    }
    return num;
}

void changeInd(int idx)
{
    arr[idx] = numOfChocolates(arr[idx]);
}

// index 0 to l-1 are guarded
// index r+1 to n are guarded
//
// l-1 to r-1
int getUnGuardedElems(int l, int r)
{

}

int tree[100005] = {0};

// {3,2,4,5}
// start = 0, end = 3
//                   (0,3):6
//          (0,1):3           (2,3):6
//      (0,0):3   (1,1):2   (2,2):6   (3,3):5
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = numOfChocolates(arr[start]);
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = (tree[2*node] >= tree[2*node+1]) ? tree[2*node] : tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(start > r || end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return ((p1 >= p2)?p1:p2);
}

void update(int node, int start, int end, int idx)
{
    if(start == end)
    {
        // Leaf node
        changeInd(idx);
        tree[node] = numOfChocolates(arr[idx]);
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx && idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx);
        }
        // Internal node will have the sum of both of its children
        tree[node] = (tree[2*node] >= tree[2*node+1]) ? tree[2*node] : tree[2*node+1];
    }
}

int main()
{
    uint32_t T = 0;
    uint16_t N = 0;
    uint16_t Q = 0;
    uint16_t i = 0;
    uint16_t j = 0;
    uint16_t k = 0;
    uint16_t t = 0;
    uint16_t l = 0;
    uint16_t r = 0;
    uint16_t ind = 0;

    scanf("%d", &T);
    scanf("%d", &N);
    scanf("%d", &Q);
    for(i = 0; i<T; i++)
    {
        for(j = 0; j<N; j++)
        {
            scanf("%d", &arr[j]);
        }
        build(1, 0, N-1);

        for(k = 0; k<Q; k++)
        {
            scanf("%d", &t);
            if(1 == t)
            {
                scanf("%d", &l);
                scanf("%d", &r);
                printf("%d\n",query(1, 0, N-1, l-1, r-1));
            }
            else if(2 == t)
            {
                scanf("%d", &ind);
                update(1, 0, N-1, ind-1);
            }
        }
        
        memset(tree, 0x0, 1000005); 
        memset(arr, 0x0, N);
    }

    return 0;
}
