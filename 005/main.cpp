#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Node
{
    int primeFactor;
    int power;
    struct Node *next;
};

void printPFList(Node *list)
{
    while (list)
    {
        cout << list->primeFactor << " " << list->power << endl;
        list = list->next;
    }
}

Node *pushNode(Node *node, Node *list)
{
    if (list == NULL)
    {
        return node;
    }
    else
    {
        node->next = list;
    }
    return node;
}

// check if prime
bool isPrime(int num)
{
    if (num < 2 || (num % 2 == 0 && num != 2))
    {
        return 0;
    }
    if (num == 2)
    {
        return 1;
    }

    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (!(num % i))
        {
            return (0);
        }
    }
    return 1;
}

// gen pf node
Node *createPFNode(int pF, int power)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        cout << "Malloc Failed" << endl;
        exit(1);
    }
    newNode->primeFactor = pF;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// get list of prime factors up to including target

Node *genPFList(int target)
{
    Node *pfList = NULL;
    for (int i = target; i > 1; i--)
    {
        if (isPrime(i))
        {
            pfList = pushNode(createPFNode(i, 0), pfList);
        }
    }
    return (pfList);
}

// get the prime factors of the target then iterate through the liked list and count occurences of the pf. if greater than the lists power increase and update.
void comparePFPower(Node *list, int target)
{
    int pf[64];
    int counter = 0;

    //zero out pf
    for(int i = 0; i < 64; i++) {
        pf[i] = 0;
    }

    cout << target << ": ";
    while (!(target % 2))
    {
        pf[counter] = 2;
        cout << pf[counter] << " ";
        counter++;
        target /= 2;
    }

    for (int i = 3; i <= sqrt(target); i += 2)
    {
        while (!(target % i))
        {
            target /= i;
            pf[counter] = i;
            cout << pf[counter] << " ";
            counter++;
        }
    }

    if (target > 2)
    {
        pf[counter] = target;
        cout << pf[counter] << " ";
    }
    cout << endl;

    while (list)
    {
        int powerCount = 0;
        for (int i = 0; i < 64; i++)
        {
            if (list->primeFactor == pf[i])
            {
                powerCount++;
            }
        }
        if (powerCount > list->power)
        {

            list->power = powerCount;
        }
        list = list->next;
    }
}

long long multiplyPFAndPowers(Node *list)
{
    long long total = 1;
    while (list)
    {
        for (int i = 0; i < list->power; i++)
        {
            total *= list->primeFactor;
        }
        list = list->next;
    }
    return total;
}

void freePFList(Node* list) {
    while (list) {
        Node* tmp = list;
        list = list->next;
        free(tmp);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }
    Node *pfList = NULL;
    int target = stoi(argv[1]);
    pfList = genPFList(target);

    cout << "Prime factors of factors:" << endl;
    for (int i = target; i > 1; i--)
    {
        comparePFPower(pfList, i);
    }

    cout << endl<< "PF | Power" << endl;
    printPFList(pfList);
    cout << endl << multiplyPFAndPowers(pfList) << endl;
    freePFList(pfList);
    return 0;
}