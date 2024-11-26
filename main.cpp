using namespace std;

#include <iostream>
#include <array>
#include <string>

class Cutie {
  private:
    string description;
    int rating;
  public:
    Cutie()
    {
      
    }

    Cutie(string d, int r)
    {
      description = d;
      rating = r;
    }
    string get_description()
    {
      return description;
    }
    int get_cuteness_rating()
    {
      return rating;
    }
};

template<typename T>
class QueueTie
{
    private:
      const int MAX_SIZE;
      T *arr;
      T *top;
      T *start;
      int arr_size;
    public:
      QueueTie(int max) : MAX_SIZE(max)
      {
        arr = new T[MAX_SIZE];
        top = arr;
        start = arr;
      }

      void enqueue(T push)
      {
        if (arr + MAX_SIZE == top)
        {
          throw std::invalid_argument("Queue is Full!");
        } else {
          *top = push;
          top++;
          arr_size++;
        }
      }

      T dequeue()
      {
        if(top == start)
        {
          throw std::invalid_argument("Queue is Empty!");
        } else {
          T popped = *start;
          for (int i = 0; i < MAX_SIZE - 1; i++)
          {
            arr[i] = arr[i+1];
          }
          top--;
          arr_size--;
          return popped;
        }
      }

      T peek()
      {
        if (top == start)
        {
          throw std::invalid_argument("Queue is Empty!");
        } else {
          T popped = *start;
          return popped;
        }
      }

      int size()
      {
        return arr_size;
      }
};

int main()
{
  QueueTie<Cutie> queue(5);

  try
  {
    queue.dequeue();
  }
  catch(std::invalid_argument &e)
  {
    cerr << e.what() << endl;
  }

  try
  {
    queue.peek();
  }
  catch(std::invalid_argument &e)
  {
    cerr << e.what() << endl;
  }

  Cutie c1("Puppy", 10);
  Cutie c2("Kitten", 9);
  Cutie c3("Parakeet", 7);
  Cutie c4("Hamster", 8);
  Cutie c5("Ferret", 7);
  Cutie c6("Fish", 4);

  queue.enqueue(c1);
  queue.enqueue(c2);
  queue.enqueue(c3);
  queue.enqueue(c4);
  queue.enqueue(c5);

  try
  {
    queue.enqueue(c6);
  }
  catch(std::invalid_argument &e)
  {
    cerr << e.what() << endl;
  }

  Cutie pop1 = queue.dequeue();
  cout << queue.peek().get_description() << endl;
  Cutie pop2 = queue.dequeue();
  cout << queue.peek().get_description() << endl;
  Cutie pop3 = queue.dequeue();
  cout << queue.peek().get_description() << endl;
  Cutie pop4 = queue.dequeue();
  cout << queue.peek().get_description() << endl;
  Cutie pop5 = queue.dequeue();

  try
  {
    queue.dequeue();
  }
  catch(std::invalid_argument &e)
  {
    cerr << e.what() << endl;
  }

  cout << pop1.get_description() << " : " << pop1.get_cuteness_rating() << endl;
  cout << pop2.get_description() << " : " << pop2.get_cuteness_rating() << endl;
  cout << pop3.get_description() << " : " << pop3.get_cuteness_rating() << endl;
  cout << pop4.get_description() << " : " << pop4.get_cuteness_rating() << endl;
  cout << pop5.get_description() << " : " << pop5.get_cuteness_rating() << endl;

  return 0;
}