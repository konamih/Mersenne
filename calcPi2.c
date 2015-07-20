// calcPi2.c
/*
 モンテカルロ法を使って円周率を求める．
 乱数生成には優れた擬似乱数を高速に発生するメルセンヌツイスタのアルゴリズ
 ムを用いる．詳しい情報は同梱の MT.h のコメントを見よ．

 コンパイルは次のようにする

   gcc calcPi2.c -lm -O3  -o calcPi2

   オプションの意味：
      -lm : 数学ライブラリをリンク
      -O3 : できる限りの最適化を行って高速にする
      -o  : 生成する実行ファイルの名前を指定

   実行するときには次のようにコマンドライン引数を与える

   ./calcPi2 1000

*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include "MT.h"
int main(int argc, char *argv[]){
  long i, n_trial, hit = 0;
  double x,y;
  // 精密な時刻データを使って種を蒔く
  init_genrand((unsigned)(clock() * UINT_MAX) % ULONG_MAX); 
  n_trial = atol(argv[1]);
  for(i=0;i < n_trial;i++){
    x = genrand_real1();
    y = genrand_real1();
    if(y < sqrt(1.0-x*x))
      hit ++;
  }
  printf("%12.9f\n",4.0*hit/(double)n_trial);
  return 0; 
}
