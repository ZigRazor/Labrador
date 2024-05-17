#include <gtest/gtest.h>

#include "ConcurrentQueue.hpp"  // Supponiamo che LWBoundedQueue sia già testata e funzionante
#include "QueueProcessor.hpp"

using namespace DogBreeds::Labrador;

// Test per verificare che il processore elabori correttamente gli elementi
// dalla coda
TEST(QueueProcessorTest, ProcessItems) {
  auto queuePtr = std::make_shared<ConcurrentQueue<int>>();
  QueueProcessor<int> processor(queuePtr, [](const int &item) {
    // Effettua l'elaborazione dell'elemento (in questo caso, stampa l'elemento)
    std::cout << "Processed item: " << item << std::endl;
  });

  // Inserisci alcuni elementi nella coda
  for (int i = 0; i < 10; ++i) queuePtr->enqueue(i);

  // Attendiamo un po' per assicurarci che il processore abbia elaborato tutti
  // gli elementi
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // Il processore dovrebbe aver elaborato tutti gli elementi, quindi la coda
  // dovrebbe essere vuota
  ASSERT_EQ(queuePtr->size(), 0);
}

// Test per verificare che il processore si fermi correttamente quando viene
// richiesto
TEST(QueueProcessorTest, StopProcessor) {
  auto queuePtr = std::make_shared<ConcurrentQueue<int>>();
  QueueProcessor<int> processor(queuePtr, [](int &item) {
    // Effettua l'elaborazione dell'elemento (in questo caso, non fare nulla)
  });

  // Interrompiamo il processore
  processor.stop();

  // Attendiamo un po' per assicurarci che il processore abbia terminato
  // l'esecuzione
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // La coda non dovrebbe essere stata elaborata, quindi la sua dimensione
  // dovrebbe essere ancora 0
  ASSERT_EQ(queuePtr->size(), 0);
}
