#ifndef PIPELINES_PIPE_H
#define PIPELINES_PIPE_H

#include <queue>
#include <stdexcept>

namespace pipelines
{
  /**
   * \brief The exception thrown when pipelines::pipe::read() is called on an
   * empty pipe.
   * \see pipelines::pipe::read()
   */
  using empty_pipe = std::logic_error;

  /**
   * \brief The communication channel between stages.
   * \tparam T The type of the data written to, and read from, the pipe.
   */
  template <typename T>
  class pipe
  {
  public:
    using value_type = T;

  private:
    using queue_type = std::queue<value_type>;

  public:
    using size_type = typename queue_type::size_type;
    void write(const value_type& value) { m_queue.push(value); };
    [[nodiscard]] value_type read()
    {
      if (m_queue.empty())
      {
        throw empty_pipe {"cannot read from an empty pipe"};
      }
      const auto v {m_queue.front()};
      m_queue.pop();
      return v;
    }
    [[nodiscard]] bool empty() const noexcept { return m_queue.empty(); };
    [[nodiscard]] size_type size() const noexcept { return m_queue.size(); };

  private:
    queue_type m_queue;
  };
}  // namespace pipelines

#endif