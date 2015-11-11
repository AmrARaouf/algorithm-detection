//Language: MS C++


#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;

const int MAX_DISTANCE = std::numeric_limits<int>::max();

struct city_and_dist
{
    int to;
    int distance;
    
    city_and_dist()
    {
    }

    city_and_dist(int to, int distance) : to(to)
                                        , distance(distance)
    {
    }
};


struct node
{
    node() : distance(MAX_DISTANCE)
           , visited(0)
    {
    } 


    void add_neighbor_and_dist(const city_and_dist& t)
    {
        neighboors.push_back(t);
    }
    
    vector<city_and_dist> neighboors;
    int distance;
    bool visited;
    
    int number;

    bool operator<(const node& t)
    {
        return (this->distance > t.distance);
    }

};


struct graph
{
    graph(size_t num)
    {
        v.assign(num + 1, node());
        for (size_t i = 0; i < num + 1; ++i)
            v[i].number = i;
    }
    
    void add_edge(int from, int to, int distance)
    {
        v[from].add_neighbor_and_dist(city_and_dist(to, distance));
        v[to].add_neighbor_and_dist(city_and_dist(from, distance));
    }


    node& get_node(int vertex)
    {
        return v[vertex];
    }


private:
       
    vector<node> v;
};


struct number_and_distance
{
    size_t number;
    int distance;
    
    number_and_distance(size_t num, int d) : number(num)
                                       , distance(d)
    {
    }

    bool operator<(const number_and_distance& t)
    {
        return (this->distance > t.distance);
    }

};




int main()
{
    const int max_edge = 1000; 

    int n, m, capital;
    cin >> n >> m >> capital;
    
    graph t(n);
    
    for (int i = 0; i < m; ++i)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        t.add_edge(from, to, dist);
    }
    
    int dist_from_capital;
    cin >> dist_from_capital;
    
    
    
    vector<number_and_distance> queue;

    t.get_node(capital).distance = 0;
    queue.push_back(number_and_distance(capital, 0));
       
    int shafts = 0;
    
    while (!queue.empty())
    {
                
        pop_heap(queue.begin(), queue.end());
        node& node_extracted = t.get_node(queue[queue.size() - 1].number);
        queue.erase(queue.end() - 1);

        
        if (!node_extracted.visited)
        {
                                  
            node_extracted.visited = true;
            
            int delta_extr = dist_from_capital - node_extracted.distance;
            
            if (delta_extr == 0)
                ++shafts;

            if (delta_extr < -max_edge)
                break;
            
            
            vector<city_and_dist>& neighboors = node_extracted.neighboors;

            for (size_t i = 0; i < neighboors.size(); ++i)
            {
                node& curr_neighboor = t.get_node(neighboors[i].to);
                int between = neighboors[i].distance;

                int old_dist = curr_neighboor.distance; 
                int new_dist = node_extracted.distance + between;
                    
                if (new_dist < old_dist)
                {
                    curr_neighboor.distance = new_dist;
                    queue.push_back(number_and_distance(curr_neighboor.number, new_dist));
                    push_heap(queue.begin(), queue.end());
                }

                if (curr_neighboor.visited)
                {
                    int delta_neigh = dist_from_capital - curr_neighboor.distance;

                    if ((delta_extr < between) && (delta_extr > 0))
                    {
                        if (delta_neigh < between - delta_extr)
                            ++shafts;
                    }
                        
                    if ((delta_neigh < between) && (delta_neigh > 0))
                    {
                        if (delta_extr < between - delta_neigh)
                            ++shafts;
                        else 
                            if (delta_extr == between - delta_neigh)
                                ++shafts;
                    }
                }


            }
        }
    }    
    
  

    cout << shafts << endl;
    
    return 0;
}