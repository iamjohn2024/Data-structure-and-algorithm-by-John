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
�������Ķ���character,������OS��queue�������ȡscanf�ַ�
���ֻ�����֣���ѡ%d�����ǳ������ֺͿո�/tab/enter����������������� 
*/
