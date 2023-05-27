////
//// Created by Eli Calabrese on 9/5/2022.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#define formatBool(b) ((b) ? "true" : "false")
//
//bool previousValue(int num) {
//    static int i = 0;
//
//    if (num == i) {
//        i = num;
//        return true;
//    }
//    i = num;
//    return false;
//}
//
//int main(int argc, char** argv) {
//    if(argc < 2) {
//        exit(3);
//    }
//
//    for(int i = 0; i < (argc - 1); ++i) {
//        bool returnValue = previousValue(atoi(argv[i]));
//        printf("%s\n", formatBool(returnValue));
//    }
//
//    return 0;
//}