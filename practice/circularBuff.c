// host ring arrHost[10]
// 1. take the data from the arrHost from start index
// 2. check if the array if empty. If so then no need to proceed and go to step 1
// 3. If the data is present in arrHost[] then check if the arrCard[] is full or not
// 4. if arrCard[] is not full then copy from end side index


// filled by other entities
unsigned int arrHost[5];

// consumed by otehr entities
unsigned int arrCard[5];

short int startH = 0;
short int endH   = 0;
short int startC = 0;
short int endC   = 0;

#define LEN 5
struct buff
{
    //start
    //end
    //count
    //fix at start : base
    //
}

// fill
while(1)
{
    sem_wait(full_host);
    enQHost();
    sem_signal(empty_host);
}

void copy()
{
    int err = 0;
    while(1)
    {      - - - - -
        // 1,2,3,4,5

        // buffer 1
        sem_wait(empty_host); // wait till enQHost gives signal to empty the buffer
        data = deQHost();
        // check -1
        sem_signal(full_host); // signal to enQHost to fill the buffer

        // buffer 2
        sem_wait(full_card);
        err = enQCard(data);
        // check -1
        sem_signal(empty_card);
    }
}

int deQHost()
{
    if(0 == countH)
    {
        // underflow
        return -1;
    }
    int data = arrHost[startH];
    startH = (startH+1)%LEN;
    countH--;

    return data;
}

int enQCard(int data)
{
    if(countC > LEN)
    {
        // overflow
        return -1;
    }
    endC = (endC+1)%LEN;
    arrHost[endC] = data;
    countC++;

    return 0;
}
