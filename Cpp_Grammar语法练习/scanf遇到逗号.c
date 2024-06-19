#include <stdio.h>

main ()
{
  int operand1, operand2, result;
  printf ("Enter two integers to sum, separated by a blank space\n");
  scanf ("%d %d", &operand1, &operand2);
  result = operand1 + operand2;
  printf ("%d + %d = %d\n", operand1, operand2, result);
}

/*
正常读的都是character,而且在OS的queue里逐个读取scanf字符
如果只读数字，就选%d，但是除了数字和空格/tab/enter，其他输入会变成乱码 
*/
