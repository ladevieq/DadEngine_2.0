#include "TArray.hpp"
#include <stdio.h>

#include "../../Platform/Types.hpp";
#include "../../Memory/LinearStackAllocator.hpp"
#include "../../Iterators/LinearStackIterator.hpp"


namespace DadEngine::Core //::Containers
{
    namespace Test
    {
        void TestTArray()
        {
            TArray<int32> eray;
            TArray<int32> bray;

            eray.Add(10);
            eray.Add(20);
            eray.Add(30);

            printf("%d\n", eray[0]);
            printf("%d\n", eray[1]);
            printf("%d\n", eray[2]);

            eray.Clear();

            bray = eray;

            for (int32 i : eray)
            {
                printf("%d\n", i);
            }

            eray.Add(10);
            eray.Add(20);

            eray[0U] = 10;

            /*printf("%d\n", bray[0]);
            printf("%d\n", bray[1]);
            printf("%d\n", bray[2]);*/

            // ASSERT(eray.IsEmpty() == TRUE);

            eray.Resize(100U);

            ASSERT(eray.Size() == 100U);

            eray.Resize(10U);

            ASSERT(eray.Size() == 10U);

            eray.Add(10);

            ASSERT(eray.IsEmpty() == FALSE);
        }
    } // namespace Test
} // namespace DadEngine::Core