/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVELEDGER_DATABASE_DATABASE_ACTIVITY_INFO_H_
#define BRAVELEDGER_DATABASE_DATABASE_ACTIVITY_INFO_H_

#include <string>

#include "bat/ledger/internal/database/database_table.h"

namespace ledger {
namespace database {

class DatabaseActivityInfo: public DatabaseTable {
 public:
  explicit DatabaseActivityInfo(LedgerImpl* ledger);
  ~DatabaseActivityInfo() override;

  void InsertOrUpdate(
      type::PublisherInfoPtr info,
      ledger::ResultCallback callback);

  void NormalizeList(
      type::PublisherInfoList list,
      ledger::ResultCallback callback);

  void GetRecordsList(
      const int start,
      const int limit,
      type::ActivityInfoFilterPtr filter,
      ledger::PublisherInfoListCallback callback);

  void DeleteRecord(
      const std::string& publisher_key,
      ledger::ResultCallback callback);

 private:
  void CreateInsertOrUpdate(
      type::DBTransaction* transaction,
      type::PublisherInfoPtr info);

  void OnGetRecordsList(
      type::DBCommandResponsePtr response,
      ledger::PublisherInfoListCallback callback);
};

}  // namespace database
}  // namespace ledger

#endif  // BRAVELEDGER_DATABASE_DATABASE_ACTIVITY_INFO_H_
