/* Copyright (c) 2018 - present, VE Software Inc. All rights reserved
 *
 * This source code is licensed under Apache 2.0 License
 *  (found in the LICENSE.Apache file in the root directory)
 */

#ifndef CONSENSUS_WAL_WAL_H_
#define CONSENSUS_WAL_WAL_H_

#include "base/Base.h"
#include "consensus/LogIterator.h"

namespace vesoft {
namespace vgraph {
namespace consensus {

/**
 * Base class for all WAL implementations
 */
class Wal {
public:
    virtual ~Wal() = default;

    // Return the ID of the last log message in the WAL
    virtual LogID lastLogId() const = 0;

    // Append one log message to the WAL
    virtual bool appendLog(LogID id, std::string msg) = 0;

    // Append a list of log messages to the WAL
    virtual bool appendLogs(LogIterator& iter) = 0;

    // Scan [firstLogId, lastLogId]
    virtual std::unique_ptr<LogIterator> iterator(int64_t firstLogId) = 0;
};

}  // namespace consensus
}  // namespace vgraph
}  // namespace vesoft
#endif  // CONSENSUS_WAL_WAL_H_
