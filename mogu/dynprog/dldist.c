
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <string.h>
#include <stdio.h>

int damerau_levenshtein(char *word1, char *word2)
{
  int len1 = strlen(word1);
  int len2 = strlen(word2);

  int matrix[len1+1][len2+1];
  for (int i=0; i<=len1; i++) matrix[i][0] = i;
  for (int j=0; j<=len2; j++) matrix[0][j] = j;

  for (int i=1; i<=len1; i++) {
    for (int j=1; j<=len2; j++) {
      int cost = 0;
      if (word1[i]!=word2[j]) cost = 1;
      int delcost = matrix[i-1][j] + 1;
      int inscost = matrix[i][j-1] + 1;
      int subcost = matrix[i-1][j-1] + cost;
      int score = MIN(MIN(delcost, inscost), subcost);
      if ((i>1) & (j>1) & (word1[i]==word2[j-1]) & (word1[i-1]==word2[j])) {
	score = MIN(matrix[i][j], matrix[i-2][j-2]+cost);
      }
    }
  }
  for (int i=0; i<=len1; i++) for (int j=0; j<=len2; j++) {
      printf("%i %i %i\n", i, j, matrix[i][j]);
    }
  return(matrix[len1][len2]);
}

int main() {
  printf("driver driver %i\n", damerau_levenshtein("driver", "diver"));
}