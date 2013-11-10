void find_length(char *input){

    printf("%s\n", input);
    int length = 0;
    while(input[length]!='\0')  //  remove ;
    {
        length++;
        printf("%i\n", length);
    }

}

