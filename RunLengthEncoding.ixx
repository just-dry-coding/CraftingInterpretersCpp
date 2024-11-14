#include<iostream>
#include<utility>
#include<vector>

export module RunLengthEncoding;


export template<typename ValueT>
class RunLengthEncoding {
	struct EncodedEntry {
		size_t upperOriginIndex;
		ValueT value;
	};

	std::vector<EncodedEntry> m_indexValuePairs;
public:
	void add(ValueT const& v) {
		if (m_indexValuePairs.empty()) {
			m_indexValuePairs.push_back({ 0, v });
			return;
		}
		auto& latestEntry = m_indexValuePairs.back();
		if (latestEntry.value == v) {
			latestEntry.upperOriginIndex++;
			return;
		}
		return m_indexValuePairs.push_back({ latestEntry.upperOriginIndex + 1, v });
	}
	ValueT get(size_t originIndex) const {
		auto it = std::lower_bound(
			m_indexValuePairs.begin(),
			m_indexValuePairs.end(),
			originIndex,
			[](const EncodedEntry& entry, size_t idx) {
				return entry.upperOriginIndex < idx;
			}
		);
		return it->value;
	}
};