import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.net.*;
import java.io.*;
import javax.imageio.ImageIO;
import javax.swing.*;

public class client extends JFrame
{
    Socket socket1;
    BufferedReader br2;
    PrintWriter out1;

    private final JLabel heading=new JLabel();
    private final JTextArea messageArea=new JTextArea();
    private final JTextField messageInput=new JTextField();
    private final Font font=new Font("Roboto",Font.PLAIN,35);

    public client()
    {
        try
        {
            System.out.println("sending request to the server\n");
            socket1=new Socket("127.0.0.1",7777);
            System.out.println("connected successfully\n");

            br2=new BufferedReader(new InputStreamReader(socket1.getInputStream()));
            out1=new PrintWriter(socket1.getOutputStream());

            createGUI();
            handleEvent();

            startReading();
            //startwriting();
        }
        catch (Exception e)
        {
            throw new RuntimeException(e);
        }
    }

    private void handleEvent()
    {
        messageInput.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e)
            {

            }

            @Override
            public void keyPressed(KeyEvent e)
            {

            }

            @Override
            public void keyReleased(KeyEvent e)
            {
                System.out.println("key released"+e.getKeyCode());
                if(e.getKeyCode()==10)
                {
                    String contentToSend=messageInput.getText();
                    messageArea.append("you :- "+contentToSend+"\n");
                    out1.println(contentToSend);
                    out1.flush();
                    messageInput.getText();
                    messageInput.requestFocus();
                }

            }
        });
    }

    private void createGUI()
    {
        this.setTitle("SamChat---c");
        this.setSize(500,500);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        heading.setFont(font);
        messageArea.setFont(font);
        messageInput.setFont(font);

        heading.setIcon(new ImageIcon("sam.png"));
        try {
            Image img = ImageIO.read(getClass().getResource("sam.png"));
            heading.setIcon(new ImageIcon(img));
        } catch (IOException e) {
            System.err.println("Error loading icon: " + e.getMessage());
        }

        heading.setHorizontalTextPosition(SwingConstants.CENTER);
        heading.setVerticalTextPosition(SwingConstants.BOTTOM);
        heading.setHorizontalAlignment(SwingConstants.CENTER);
        heading.setBorder(BorderFactory.createEmptyBorder(20,20,20,20));

        messageArea.setEnabled(false);
        messageInput.setHorizontalAlignment(SwingConstants.CENTER);

        this.setLayout(new BorderLayout());

        this.add(heading,BorderLayout.NORTH);
        JScrollPane jScrollPane=new JScrollPane(messageArea);
        this.add(jScrollPane,BorderLayout.CENTER);
        this.add(messageInput,BorderLayout.SOUTH);

        this.setVisible(true);

    }
    public void startReading()
    {
        Runnable r1;
        r1 = ()->
        {
            System.out.println("reader reading the massage....\n");

            try
            {
                while (true)
                {
                    String msg = br2.readLine();
                    if (msg.equalsIgnoreCase("exit"))
                    {
                        System.out.println("server want to exit\n");
                        JOptionPane.showMessageDialog(this,"server terminated the chat");
                        messageInput.setEnabled(false);
                        break;
                    }
                    //System.out.println("server :- " + msg);
                    messageArea.append("user :- " + msg+"\n");
                }
            }
            catch (Exception e)
            {
                //throw new RuntimeException(e);
                System.out.println("\n\nconnection closed\n\n");
            }
        };
        new Thread(r1).start();
    }

    public void startwriting()
    {
        Runnable r2;
        r2 = ()->
        {
            System.out.println("writer started writing...\n");
            try
            {
                while (!socket1.isClosed())
                {
                    BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
                    String content = br1.readLine();
                    out1.println(content);
                    out1.flush();
                    if(content.equals("exit"))
                    {
                        socket1.close();
                        break;
                    }
                }

            }
            catch (Exception e)
            {
                //throw new RuntimeException(e);
                System.out.println("\n\nconnection closed\n\n");
            }
        };
        new Thread(r2).start();
    }

    public static void main(String[] args)
    {
        System.out.println("this is client side server....\n");
        new client();
    }
}
