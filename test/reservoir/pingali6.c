/* Generated from ./reservoir/pingali6.cloog by CLooG 0.18.1-2-g43fc508 gmp bits in 0.01s. */
if (N >= 3) {
  for (c4=2;c4<=N-1;c4++) {
    for (c6=2;c6<=N-1;c6++) {
      S1(1,c4,c6);
    }
  }
  for (c2=3;c2<=2*M;c2++) {
    for (c4=2;c4<=N-1;c4++) {
      for (c6=2;c6<=N-1;c6++) {
        if (c2%2 == 0) {
          S1((c2/2),c4,c6);
        }
      }
    }
    for (c4=2;c4<=N-1;c4++) {
      for (c6=2;c6<=N-1;c6++) {
        if ((c2+1)%2 == 0) {
          S2(((c2-1)/2),c4,c6);
        }
      }
    }
  }
  for (c4=2;c4<=N-1;c4++) {
    for (c6=2;c6<=N-1;c6++) {
      S2(M,c4,c6);
    }
  }
}
