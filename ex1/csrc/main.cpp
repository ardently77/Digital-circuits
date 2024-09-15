#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<verilated.h>
#include<verilated_vcd_c.h>//生成波形图头文件
#include"Vtop.h"//V转为CPP文件的接口定义，信号声明等
 
#define MAX_SIM_TIME 20
 
vluint64_t sim_time=0;//vluint64_t是Verilator 中定义的一个类型，用于表示仿真时间
 
int main(int argc,char** argv,char** env){
 
	Vtop *top=new Vtop; //定义一个V类对象
 
  Verilated::traceEverOn(true);                                                                                                                     
  VerilatedVcdC *m_trace=new VerilatedVcdC;//VerilatorVcdC 类型的对象，用于表示波形跟踪器，它负责管理波形文件的生成
  top->trace(m_trace,0);//数字代表跟踪深度
  m_trace->open("Wave.vcd");

  while(sim_time<MAX_SIM_TIME){
     int a,b,s;
     a=rand()&1;
     b=rand()&1;
     //s=rand()&1;
     top->a=a;
     top->b=b;
     //top->s=s;
     top->eval();//输入后调用更新输出
     printf("%d %d %d %d\n",a,b,s,top->f);
     m_trace->dump(sim_time);//仿真时间向后推
     sim_time++;
   }

   m_trace->close();
   delete top;
   exit(EXIT_SUCCESS);
 }

