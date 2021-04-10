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
  class pipe final
  {
  public:
    /// The type of the data that can a pipe object can hold.
    using value_type = T;

  private:
    using queue_type = std::queue<value_type>;

  public:
    /// The type of the pipe size.
    using size_type = typename queue_type::size_type;

    /**
     * \brief Write an element to the pipe.
     * \param[in] value The element to write.
     */
    void write(const value_type& value) { m_queue.push(value); }

    /**
     * \brief Read one element from the pipe.
     * \return The first data element available in the pipe.
     * \throws pipelines::empty_pipe if the pipe is empty.
     */
    [[nodiscard]] auto read()
    {
      if (m_queue.empty())
      {
        throw empty_pipe {"cannot read from an empty pipe"};
      }
      const auto v {m_queue.front()};
      m_queue.pop();
      return v;
    }

    /**
     * \brief Check if the pipe is empty.
     * \retval true Indicates there are no elements in the pipe.
     * \retval false Indicates there is at least one element in the pipe.
     */
    [[nodiscard]] auto empty() const noexcept { return m_queue.empty(); }

    /**
     * \brief Get the number of elements in the pipe.
     * \return The number of elements in the pipe.
     */
    [[nodiscard]] auto size() const noexcept { return m_queue.size(); }

  private:
    // TODO This needs to be made thread safe.
    queue_type m_queue;
  };
}  // namespace pipelines

#endif