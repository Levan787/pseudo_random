unsigned long srand = 0;

int getBit(unsigned long num,int index){
    return (num<<(index-1))>>31;
}

unsigned long lfsr32C(unsigned long seed){
    if(seed == 0){
        int temp;
        temp = getBit(srand,25) ^ getBit(srand,26);
        temp ^= getBit(srand,30);
        temp ^= getBit(srand,32);

        temp <<= 31;
        srand >>=1;
        srand |= temp;
    }else{
        srand = seed;
        lfsr32C(0);
        return srand;
    }
    return srand;
}
