//Language: MS C++


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <functional>
#include <hash_set>

// Types definition
// 
typedef signed char                 int8;
typedef unsigned char               uint8;
typedef signed short                int16;
typedef unsigned short              uint16;
typedef signed long                 int32;
typedef unsigned long               uint32;
typedef signed long long            int64;
typedef unsigned long long          uint64;

typedef std::vector<size_t>         SizeTVector;
typedef std::set<size_t>            SizeTSet;
typedef std::multiset<size_t>       SizeTMultiset;

typedef std::vector<std::string>    StringVector;
typedef std::set<std::string>       StringSet;
typedef std::multiset<std::string>  StringMultiset;

// Auxiliary functions definition
// 
inline void DoNothing() { }
template<typename T> inline T Abs(const T a) { return a < 0 ? -a : a; }
template<typename T> inline T Min(const T a, const T b) {return a < b ? a : b;}
template<typename T> inline T Max(const T a, const T b) {return a > b ? a : b;}

static const double eps = 1.0e-8;
inline double IsEqual(const double a, const double b) { return Abs(a - b) < eps; }
inline double IsGreater(const double a, const double b) { return a > b + eps; }
inline double IsLess(const double a, const double b) { return a + eps < b; }

struct Rand
{
    uint32 z_, w_;
    uint32 get32() { z_ = 36969 * (z_ & 65535) + (z_ >> 16); w_ = 18000 * (w_ & 65535) + (w_ >> 16); return (z_ << 16) + (w_ & 65535); }
    void Reset() { z_ = 1; w_ = 1; }
    Rand() { Reset(); }
};

template <typename T> inline std::vector<std::vector<T> > CreateVector2d(const size_t rowCnt, const size_t colCnt)
{
    return std::vector<std::vector<T> > (rowCnt, std::vector<T>(colCnt));
}

#ifndef ONLINE_JUDGE
#define PRINT(a) std::cout << '\t' << #a << " = " << (a) << "; "
#define NEWLINE() std::cout << std::endl;
#else //ONLINE_JUDGE
#define PRINT(a) DoNothing()
#define NEWLINE() DoNothing()
#endif //ONLINE_JUDGE

// Auxiliary functions forward definition
// 
void Prepare();

class StopWatchEx
{
public:
    StopWatchEx();
    ~StopWatchEx();

private:
    struct Data;    
    Data *pData;
};



// Local functions definition
// 
typedef uint16  VertexId;
typedef stdext::hash_set<VertexId>              VertexHashSet;
typedef std::vector<VertexId>                   VertexVector;
typedef std::vector<std::vector<VertexId> >     VertexVector2d;

struct DataField
{
    uint16 be;
    uint32 minWay;

    DataField(): be(0), minWay(0) {}
};

typedef std::vector<std::vector<DataField> >    DataFieldVector2d;

struct TwoPoints
{
    VertexId a, b;

    bool operator<(const TwoPoints& rval) const
    {
        if (a < rval.a) { return true; }
        else if (rval.a < a) { return false; }
        else { return b < rval.b; }
    }

    TwoPoints(const VertexId _a, const VertexId _b): a(_a), b(_b) {}
};

typedef std::map<TwoPoints, VertexHashSet>      MapEdgeToVertexSet;

typedef stdext::hash_set<size_t>                SizeTHashSet;
typedef std::vector<std::vector<size_t> >       SizeTVector2d;
typedef std::vector<std::set<size_t> >          SizeTSetVector;
typedef std::vector<std::vector<SizeTHashSet> > HashSetVector2d;

struct Edge
{
    VertexId from;
    VertexId to;
    uint32 minWayPrev;
    Edge(const VertexId _from, const VertexId _to, const uint32 _minWayPrev): from(_from), to(_to), minWayPrev(_minWayPrev) {}
};

typedef std::deque<Edge>                        EdgeDeque;


template<typename T>
inline bool IsFound(const stdext::hash_set<T>& container, const T val)
{
    return (container.find(val) != container.end());
}

inline bool IsForbidden(const MapEdgeToVertexSet& mapping, const TwoPoints& ab, const VertexId c)
{
    MapEdgeToVertexSet::const_iterator pI = mapping.find(ab);
    if (pI != mapping.end() && 
        pI->second.find(c) != pI->second.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

inline bool IsForbidden(const MapEdgeToVertexSet& mapping, const VertexId a, const VertexId b, const VertexId c)
{
    return IsForbidden(mapping, TwoPoints(a, b), c);
}

inline bool IsLinked(const VertexVector2d& linksSorted, const VertexId a, const VertexId b)
{
    const VertexVector& links_a = linksSorted[a];
    return std::binary_search(links_a.begin(), links_a.end(), b);
}

bool Solve(bool bCheckInputStream = false)
{
    // First input operation
    //
    VertexId n;
    size_t m, k;
    std::cin >> n >> m >> k;

    if (bCheckInputStream && !std::cin)
    {
        return false;
    }

    StopWatchEx _sw;


    VertexVector2d links(n);
    MapEdgeToVertexSet forbidden;
    // Other input operations and calculations
    //

    for (size_t i = 0; i < m; ++i)
    {
        VertexId x, y;
        std::cin >> x >> y;
        --x; --y;
        links[x].push_back(y);
        links[y].push_back(x);
    }

    for (VertexId i = 0; i < n; i++)
    {
        std::sort(links[i].begin(), links[i].end());
    }

    for (size_t i = 0; i < k; ++i)
    {
        VertexId a, b, c;
        std::cin >> a >> b >> c;
        --a; --b; --c;
        forbidden[TwoPoints(a, b)].insert(c);
    }

    DataFieldVector2d data = CreateVector2d<DataField>(n, n);

    const VertexId startId = 0;
    const VertexId stopId = n-1;

    EdgeDeque queue;
    // first step
    for(size_t i = 0; i < n; i++)
    {
        data[i][startId].minWay = 0;
        data[i][startId].be = 1;
    }
    for(size_t i = 0; i < links[startId].size(); ++i)
    {
        queue.push_back(Edge(startId, links[startId][i], 0));
    }

    // other steps
    while (!queue.empty())
    {
        const size_t queueSize = queue.size();

        for (size_t i = 0; i < queueSize; i++)
        {
            const Edge& nextEdge = queue.at(0);
            const size_t nextId = nextEdge.to;

            if (!data[nextEdge.from][nextEdge.to].be || 
                data[nextEdge.from][nextEdge.to].minWay > nextEdge.minWayPrev + 1)
            {
                data[nextEdge.from][nextEdge.to].be = 1;
                data[nextEdge.from][nextEdge.to].minWay = nextEdge.minWayPrev + 1;

                for (size_t i = 0; i < links[nextId].size(); i++)
                {
                    const VertexId nextNextId = links[nextId][i];
                    if (!data[nextEdge.to][nextNextId].be)
                    {
                        if (!IsForbidden(forbidden, TwoPoints(nextEdge.from, nextEdge.to), nextNextId))
                        {
                            queue.push_back(Edge(nextEdge.to, nextNextId, data[nextEdge.from][nextEdge.to].minWay));
                        }
                    }
                }
            }
            queue.pop_front();
        }
    }

    VertexVector sequence;
    bool bReached = false;
    uint32 stepCnt = 0;

    for (size_t i = 0; i < n; ++i)
    {
        if (data[i][stopId].be && (!bReached || data[i][stopId].minWay < stepCnt))
        {
            bReached = true;
            stepCnt = data[i][stopId].minWay;
        }
    }

    if (bReached)
    {
        VertexId curId = stopId;
        sequence.push_back(curId);

        while (curId != startId)
        {
            bool bNextStepFound = false;
            VertexId prevId = 0;
            for (VertexId i = 0; i < n; ++i)
            {
                if (IsLinked(links, i, curId) && data[i][curId].minWay == stepCnt)
                {
                    bNextStepFound = true;
                    prevId = i;
                    break;
                }
            }
            if (!bNextStepFound) 
            { 
                break; 
            }
            
            curId = prevId;
            sequence.push_back(curId);
            --stepCnt;
        }

        std::reverse(sequence.begin(), sequence.end());

        std::cout << sequence.size() - 1 << std::endl;
        for(size_t i = 0; i < sequence.size(); ++i)
        {
            std::cout << sequence[i] + 1 << ' ';
        }
    }
    else
    {
        std::cout << "-1" << std::endl;
    }

    return true;
    // End of all calculations
}

int main()
{
    Prepare();

#if defined(ONLINE_JUDGE)
    Solve();
#else //defined(ONLINE_JUDGE)
    while (Solve(true)) { }
    //Solve();
#endif //defined(ONLINE_JUDGE)
}








// Test-specific stuff

#if !defined(ONLINE_JUDGE)
#endif // !defined(ONLINE_JUDGE)

#if !defined(ONLINE_JUDGE)
#include <windows.h>
#endif //!defined(ONLINE_JUDGE)

struct StopWatchEx::Data
{
#if !defined(ONLINE_JUDGE)
    FILETIME timeStartSystem;
    FILETIME timeStartUser;
#endif //!defined(ONLINE_JUDGE)
};

StopWatchEx::StopWatchEx()
{
#if !defined(ONLINE_JUDGE)
    pData = new Data();
    FILETIME dummy;
    GetProcessTimes(GetCurrentProcess(), &dummy, &dummy, &dummy, &pData->timeStartUser);
    GetSystemTimeAsFileTime(&pData->timeStartSystem);
#endif //!defined(ONLINE_JUDGE)
}

#if !defined(ONLINE_JUDGE)
ULONGLONG FileTimeToU64(const FILETIME& time)
{
    return ((ULONGLONG)time.dwHighDateTime << 32) | time.dwLowDateTime;
}

ULONGLONG GetTimeDiffMs(const FILETIME& first, const FILETIME& second)
{
    return ((FileTimeToU64(first) - FileTimeToU64(second)) + 9999) / 10000;
}
#endif // !defined(ONLINE_JUDGE)

StopWatchEx::~StopWatchEx()
{
#if !defined(ONLINE_JUDGE)
    FILETIME timeCreated;
    FILETIME timeStopUser;
    FILETIME dummy;
    GetProcessTimes(GetCurrentProcess(), &timeCreated, &dummy, &dummy, &timeStopUser);

    FILETIME timeCurrent;
    GetSystemTimeAsFileTime(&timeCurrent);

    std::cout << std::setw(20) << "Total process = " << GetTimeDiffMs(timeCurrent, timeCreated) << " ms" << std::endl;
    std::cout << std::setw(20) << "UserTime diff = " << GetTimeDiffMs(timeStopUser, pData->timeStartUser) << " ms" << std::endl;
    std::cout << std::setw(20) << "SysTime diff = " << GetTimeDiffMs(timeCurrent, pData->timeStartSystem) << " ms" << std::endl;
    std::cout << std::endl;

    delete pData;
#endif //!defined(ONLINE_JUDGE)
}

void Prepare()
{
#if !defined(ONLINE_JUDGE)
    SetProcessAffinityMask(GetCurrentProcess(), 1);
#endif //!defined(ONLINE_JUDGE)
}