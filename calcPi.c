// calcPi.c
/*
 モンテカルロ法を使って円周率を求める．
 乱数生成には優れた擬似乱数を高速に発生するメルセンヌツイスタのアルゴリズ
 ムを用いる．詳しい情報は同梱の MT.h のコメントを見よ．

 コンパイルは次のようにする

   gcc calcPi.c -lm -O3  -o calcPi

   オプションの意味：
      -lm : 数学ライブラリをリンク
      -O3 : できる限りの最適化を行って高速にする
      -o  : 生成する実行ファイルの名前を指定

   実行するときには次のようにコマンドライン引数を与える

   ./calcPi 1000

*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "MT.h"
#include <limits.h>
int main(int argc, char *argv[]){
  long i, n_trial, hit = 0;
  double x,y;
  clock_t  time1, time2;
  init_genrand((unsigned)(clock() * UINT_MAX) % ULONG_MAX); // 時刻データで種を蒔く
  n_trial = atol(argv[1]);
  time1 = clock();
  printf("time2= %f\n",(double)time1);
  for(i=0;i < n_trial;i++){
    x = genrand_real1();
    y = genrand_real1();
    if(y < sqrt(1.0-x*x))
      hit ++;
  }
  time2 = clock();
  printf("%12.9f\n",4.0*hit/(double)n_trial);
  printf("経過時間: %7.3f 秒\n", (double)(time2 - time1) / CLOCKS_PER_SEC);
  return 0; /*なくともよい */
}
