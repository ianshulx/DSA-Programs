#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct process
{
    int nodeId;
    int nodeValue;
} * PROCESS;

typedef struct event
{
    int eventSource;
    int eventTarget;
    int eventType;
    int eventFlag;
    int eventValue;
    struct event *eventNext;
} * EVENT;

EVENT initialization(EVENT evt)
{
    evt = (EVENT)malloc(sizeof(struct event));
    evt->eventNext = NULL;
    return evt;
}

int isEmpty(EVENT evt)
{
    if(evt->eventNext == NULL){
        return 1;
    }
    return 0;
}

PROCESS generateValues(PROCESS S, int n, int iFlag)
{
    S = (PROCESS)malloc(n*sizeof(struct process));
    switch (iFlag)
    {
    case 0:
        printf("\n");
        printf("\t");
        printf("Input Generation: SORTED SEQUENCE!");
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            int val = i + 1;
            S[i].nodeId = i;
            S[i].nodeValue = val;
        }
        break;
    case 1:
        printf("\n");
        printf("\t");
        printf("Input Generation: RANDOM!");
        printf("\n");
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            int val = rand() / 1000;
            S[i].nodeId = i;
            S[i].nodeValue = val;
        }
        break;
    case 2:
        printf("\n");
        printf("\t");
        printf("Input Generation: WORST CASE!");
        printf("\n");

        for (int i = 0; i < n; i++)
        {
            int val = n - i;
            S[i].nodeId = i;
            S[i].nodeValue = val;
        }
        break;
    }
    return S;
}

void printValues(PROCESS S, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d",S[i].nodeValue);
        printf("\t");
    }
}

int swapValues(int *x, int *y)
{
    int min, flg = 0;
    if (*x <= *y)
    {
        min = *x;
    }
    else
    {
        min = *y;
        *y = *x;
        *x = min;
        flg = 1;
    }
    return flg;
}

EVENT insert(EVENT evt, int eSource, int eTarget, int eType, int eFlag, int eValue)
{
    EVENT new, prev = evt, curr;
    new = (EVENT)malloc(sizeof(struct event));
    new->eventSource = eSource;
    new->eventTarget = eTarget;
    new->eventType = eType;
    new->eventFlag = eFlag;
    new->eventValue = eValue;
    new->eventNext = NULL;

    if (prev->eventNext == NULL)
    {
        prev->eventNext = new;
        return evt;
    }
    else
    {
        curr = prev;
        while (curr->eventNext != NULL)
        {
            curr = curr->eventNext;
        }
        curr->eventNext = new;
    }
    return evt;
}

EVENT extractTopEvent(EVENT evt, EVENT tp)
{
    EVENT del = evt, nxt, atop = tp;
    atop = atop->eventNext;

    if (del->eventNext != NULL)
    {
        del = del->eventNext;
        if (del->eventNext != NULL)
        {
            nxt = del->eventNext;
            evt->eventNext = nxt;
        }
        else
        {
            evt->eventNext = NULL;
        }

        atop->eventSource = del->eventSource;
        atop->eventTarget = del->eventTarget;
        atop->eventType = del->eventType;
        atop->eventFlag = del->eventFlag;
        atop->eventValue = del->eventValue;
        atop->eventNext = NULL;
        free(del);
    }
    else
    {
        printf("\n");
        printf("\t");
        printf("ERROR: No events found!!");
        tp->eventNext = NULL;
        atop->eventNext = NULL;
    }
    return tp;
}

EVENT destroyEvents(EVENT evt)
{
    EVENT del = evt, nxt;
    if (del->eventNext == NULL)
    {
        return evt;
    }
    else
    {
        del = del->eventNext;
        while (del->eventNext != NULL)
        {
            nxt = del;
            free(nxt);
            del = del->eventNext;
        }
        free(del);
        evt->eventNext == NULL;
        return evt;
    }
}

void handleSendEvents(EVENT evt, EVENT curr)
{
    EVENT cuNext = curr->eventNext;
    evt = insert(evt, cuNext->eventTarget, cuNext->eventSource, 0, cuNext->eventFlag, cuNext->eventValue);
}

void handleRecieveEvents(PROCESS S, EVENT evt, EVENT curr, int round)
{
    EVENT cuNext = curr->eventNext;
    int flag = cuNext->eventFlag, recievedValue = cuNext->eventValue;

    if (flag == 1)
    {
        bool swap = swapValues(&recievedValue, &S[cuNext->eventSource].nodeValue);
        evt = insert(evt, cuNext->eventSource, cuNext->eventTarget, 1, 0, recievedValue);
    }
    else
    {
        S[cuNext->eventSource].nodeValue = recievedValue;
    }
}

int main(int argc, char *argv[])
{
    int round = 1;
    PROCESS S = NULL;
    EVENT E, eTop, aTop;
    srand(1000);
    printf("No of Process: ");
    
    printf("%d",5);

    E = initialization(E);
    eTop = initialization(eTop);
    aTop = initialization(aTop);
    eTop->eventNext = aTop;

    S = generateValues(S, 5, 1);

    printf("\n");
    printf("\t");
    printf("Initial : ");
    printf("\t");

    for (int i = 0; i < 5; i++)
    {
        printf("%d",S[i].nodeValue);
        printf("   ");
    }

    while (round <= 5)
    {
        printf("\n");
        printf("\t");
        printf("STEP - ");
        
        printf("%d",round);
        
        printf("\t");
        
        for (int i = 0; i < 4; i++)
        {
            if (i % 2 != round % 2)
            {
                E = insert(E, i, i + 1, 1, 1, S[i].nodeValue);
            }
        }
        
        while (!isEmpty(E))
        {
            eTop = extractTopEvent(E, eTop);

            if (eTop->eventNext->eventType == 1)
            {
                handleSendEvents(E, eTop);
            }
            else
            {
                if (eTop->eventNext->eventType == 0)
                {
                    handleRecieveEvents(S, E, eTop, round);
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            printf("%d",S[i].nodeValue);
            printf("  ");
        }
        round++;
    }
    
    printf("\n");
    printf("\t");
    printf("STEP - ");
    
    printf("%d",round);
    
    printf("\t");
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d",S[i].nodeValue);
        printf("  ");
    }

    printf("\n");
    printf("\t");
    printf("RESULT: ");
    printf("\t");
    printValues(S, 5);

    E = destroyEvents(E);
    eTop = destroyEvents(eTop);
    
    free(S);
    free(E);
    free(eTop);

    printf("\n");

    return 0;
}