import java.awt.*;
import javax.swing.*;
import java.awt.event.*;



public class GUI_calculator
{
    static JFrame frame;
    static Container c;
    static JTextArea display;
    static JButton num_1,num_2,num_3,num_4,num_5,num_6,num_7,num_8,num_9,num_0,plus,minus,mul,div,eq,clear,AC;
    static char op='\0';

    static int operand1;
    static int operand2;
    public static void main(String[] args) {
        frame=new JFrame("Calculator");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        ImageIcon icon=new ImageIcon("calculator.jpeg");
//        frame.setIconImage(icon.getImage());
        frame.setBounds(0,0,600,450);
        c=frame.getContentPane();
        c.setLayout(null);

        display=new JTextArea();
        display.setBounds(20,20,400,50);
        c.add(display);
        display.setFont(new Font("Arial",Font.LAYOUT_LEFT_TO_RIGHT,40));

        AC=new JButton("AC");
        AC.setBounds(125,325,80,50);
        AC.setFont(new Font("Arial",Font.BOLD,30));
        c.add(AC);
        AC.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText("");
            }
        });

        plus=new JButton("+");
        plus.setBounds(335,90,80,50);
        plus.setFont(new Font("Arial",Font.BOLD,30));
        c.add(plus);
        plus.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                operand1= Integer.parseInt(display.getText());
                display.setText(null);
                op='+';
            }
        });

        minus=new JButton("-");
        minus .setBounds(335,175,80,50);
        minus.setFont(new Font("Arial",Font.BOLD,30));
        c.add(minus);
        minus.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                operand1= Integer.parseInt(display.getText());
                display.setText(null);
                op='-';
            }
        });

        mul=new JButton("*");
        mul.setBounds(335,250,80,50);
        mul.setFont(new Font("Arial",Font.BOLD,30));
        c.add(mul);
        mul.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                operand1= Integer.parseInt(display.getText());
                display.setText(null);
                op='*';
            }
        });

        div=new JButton("%");
        div.setBounds(335,325,80,50);
        div.setFont(new Font("Arial",Font.BOLD,30));
        c.add(div);
        div.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                operand1= Integer.parseInt(display.getText());
                display.setText(null);
                op='/';
            }
        });


        eq=new JButton("=");
        eq.setBounds(230,325,80,50);
        eq.setFont(new Font("Arial",Font.BOLD,30));
        c.add(eq);
        eq.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                operand2=Integer.parseInt(display.getText());


                System.out.println("OPERAND 1 = +"+operand1+"  Operand 2 = "+operand2  );
                display.setText(null);
                switch(op)
                {
                    case '+':display.setText(String.valueOf(operand1+operand2));
                        break;
                    case '-': display.setText(String.valueOf(operand1-operand2));
                        break;
                    case '*': display.setText(String.valueOf(operand1*operand2));
                        break;
                    case '/': display.setText(String.valueOf(operand1/operand2));
                        break;
                }

            }
        });


        num_0=new JButton("0");
        num_0.setBounds(20,325,80,50);
        num_0.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_0);
        num_0.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"0");
            }
        });







        num_1=new JButton("1");
        num_1.setBounds(20,90,80,50);
        num_1.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_1);
        num_1.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"1");
            }
        });

        num_2=new JButton("2");
        num_2.setBounds(125,90,80,50);
        num_2.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_2);
        num_2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"2");
            }
        });

        num_3=new JButton("3");
        num_3.setBounds(230,90,80,50);
        num_3.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_3);
        num_3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"3");
            }
        });

        num_4=new JButton("4");
        num_4.setBounds(20,175,80,50);
        num_4.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_4);
        num_4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"4");
            }
        });


        num_5=new JButton("5");
        num_5.setBounds(125,175,80,50);
        num_5.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_5);
        num_5.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"5");
            }
        });


        num_6=new JButton("6");
        num_6.setBounds(230,175,80,50);
        num_6.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_6);
        num_6.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"6");
            }
        });


        num_7=new JButton("7");
        num_7.setBounds(20,250,80,50);
        num_7.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_7);
        num_7.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"7");
            }
        });

        num_8=new JButton("8");
        num_8.setBounds(125,250,80,50);
        num_8.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_8);
        num_8.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"8");
            }
        });
        num_9=new JButton("9");
        num_9.setBounds(230,250,80,50);
        num_9.setFont(new Font("Arial",Font.BOLD,30));
        c.add(num_9);
        num_9.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                display.setText(display.getText()+"9");
            }
        });

        frame.setVisible(true);
    }
}